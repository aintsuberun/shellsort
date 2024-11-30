#include "server.h"
#include "SortingByShellLibrary.h"

#include <QDebug>
Server::Server(QObject *parent)
    : QTcpServer(parent)
{

    if (!connectToDatabase()) {
        qDebug() << "Failed to connect to database.";
        return;
    }
    if (listen(QHostAddress::Any, 12345)) {
        qDebug() << "Server started on port 12345.";
    } else {
        qDebug() << "Failed to start server:" << errorString();
    }
}

Server::~Server(){
    if (db.isOpen()) db.close();
}
bool Server::connectToDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("arrays_database");
    db.setUserName("root");
    db.setPassword("1234rps");
    return db.open();
}
void Server::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketDescriptor);
    connect(client, &QTcpSocket::readyRead, this, &Server::readClient);
    connect(client, &QTcpSocket::disconnected, this, &Server::clientDisconnected);
    qDebug() << "Client connected:" << client->peerAddress().toString();
}


void Server::readClient() {
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;
    QByteArray data = client->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();
    QString action = json["action"].toString();
    if(action == "get_elements"){// Выполняем запрос к базе данных для получения элементов данного массива
        QSqlQuery query;
        query.exec("SELECT * FROM arrays");
        // Заполняем JSON-массив данными из базы
        QJsonArray arraysArray;
        while(query.next()){
            QJsonObject arrayObject;
            arrayObject["id"] = query.value("id").toInt();
            arrayObject["name"] = query.value("name").toString();
            arraysArray.append(arrayObject);
        }
        query.exec("SELECT * FROM elements");
        QJsonArray elementsArray;
        while (query.next()) {
            QJsonObject elementObject;
            elementObject["array_id"] = query.value("array_id").toInt();
            elementObject["id"] = query.value("id").toInt();
            elementObject["value"] = query.value("value").toInt();
            elementsArray.append(elementObject);
        }
        QJsonObject response;// Создаем JSON-объект и добавляем в него массив элементов
        response["arrays"] = arraysArray;
        response["elements"] = elementsArray;
        response["action"] = "get_elements";
        QJsonDocument doc(response);// Преобразуем объект в JSON строку
        QByteArray data = doc.toJson();
        client->write(data);
    }
    if(action == "get_elements_id"){
        QSqlQuery query;
        query.prepare("SELECT * FROM elements WHERE array_id = :array_id");
        query.bindValue(":array_id", json["id"].toInt());
        query.exec();
        QJsonArray elementsArray;
        while (query.next()) {
            QJsonObject elementObject;
            elementObject["id"] = query.value("id").toInt();
            elementObject["value"] = query.value("value").toInt();
            elementsArray.append(elementObject);
        }
        QJsonObject response;
        response["elements"] = elementsArray;
        response["action"] = "get_elements_id";
        response["id"] = json["id"].toInt();
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);
        client->flush();
    }
    if(action == "delete_all"){
        QSqlQuery query;
        query.exec("DELETE FROM arrays; ALTER TABLE arrays AUTO_INCREMENT = 1;");

        QJsonObject response;
        response["action"] = "delete_all";
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);
        client->flush();
    }
    
    if(action == "insert_elements"){
        QJsonArray elementsArray = json["elements"].toArray();
        QSqlQuery query;
        if(json["array_id"].toInt() == -1){
            query.exec("INSERT INTO arrays (name) VALUES ('not_sorted');SET @id = LAST_INSERT_ID();");
            QString po = "INSERT INTO elements (array_id, id, value) VALUES ";
            for(int i = 0; i < elementsArray.size();i++){
                QJsonObject element = elementsArray[i].toObject();
                if(i != 0){
                    po += ", ";
                }
                po += "(@id, " + std::to_string(element["id"].toInt()) + ", " + std::to_string(element["value"].toInt()) + ")";
            }
            po += ";";
            query.exec(po);
        }
        else{
            query.prepare("INSERT INTO arrays (id, name) VALUES (:id, 'array');");
            query.bindValue(":id", json["array_id"].toInt());
            query.exec();
            query.prepare("INSERT INTO elements (array_id, id, value) VALUES (:array_id, :id, :value)");
            QVariantList arrayIds, elementIds, values;
            for(int i = 0; i < elementsArray.size();i++){
                QJsonObject element = elementsArray[i].toObject();
                arrayIds.append(json["array_id"].toInt());
                elementIds.append(element["id"].toInt());
                values.append(element["value"].toInt());
            }
            query.bindValue(":array_id", arrayIds);
            query.bindValue(":id", elementIds);
            query.bindValue(":value", values);
            query.execBatch();
        }

        QJsonObject response;
        response["action"] = "insert_elements";
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);
    }
    if (action == "sort_id") {
        int array_id = json["id"].toInt();
        QSqlQuery query;
        query.prepare("UPDATE arrays SET name = 'sorted' WHERE id = :id;");
        query.bindValue(":id", array_id);
        query.exec();
        query.prepare("SELECT * FROM elements WHERE array_id = :id;");
        query.bindValue(":id", array_id);
        query.exec();
        QList <int> lis;
        while (query.next()) {
            int elementValue = query.value("value").toInt();
            lis.push_back(elementValue);
        }
        SortingByShellLibrary::sortByShell(lis);
        for (int i = 0; i < lis.size(); i++) {
            query.prepare("UPDATE elements SET value = :value WHERE array_id = :array_id AND id = :id;");
            query.bindValue(":value", lis[i]);
            query.bindValue(":array_id", array_id);
            query.bindValue(":id", i);
            query.exec();
        }
        QJsonObject response;
        response["action"] = "sort_id";
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);
    }
    if (action == "update") {
        int array_id = json["id"].toInt();
        QJsonArray elementsArray = json["elements"].toArray();
        QSqlQuery query;
        query.prepare("DELETE FROM arrays WHERE id = :id;");//TODO fix delete
        query.bindValue(":id", array_id);
        query.exec();
        query.prepare("INSERT INTO arrays (id, name) VALUES (:id, 'not_sorted');");
        query.bindValue(":id", array_id);
        query.exec();
        query.prepare("INSERT INTO elements (array_id, id, value) VALUES (:array_id, :id, :value);");
        QVariantList arrayIds, ids, values;
        for (int i = 0; i < elementsArray.size(); i++) {
            QJsonObject elements = elementsArray[i].toObject();
            arrayIds << array_id;
            ids << elements["id"].toInt();
            values << elements["value"].toInt();

        }
        query.bindValue(":array_id", arrayIds);
        query.bindValue(":id", ids);
        query.bindValue(":value", values);
        query.execBatch();

        QJsonObject response;
        response["action"] = "update";
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);
    }
    if (action == "delete_id") {
        int id = json["id"].toInt();
        QSqlQuery query;
        query.prepare("DELETE FROM arrays WHERE id = :id;");
        query.bindValue(":id", id);
        query.exec();
        QJsonObject response;
        response["action"] = "delete_id";
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);

    }
    if(action == "sort_all"){
        QSqlQuery query;
        query.exec("SELECT * FROM elements");
        int array_id = 1;
        QList <QList<int>> lis;
        lis.resize(2);
        while (query.next()) {
            if(array_id != query.value("array_id").toInt()){
                array_id = query.value("array_id").toInt();
                if(array_id + 2 > lis.size()){
                    lis.resize(array_id + 2);
                }
            }
            int elementValue = query.value("value").toInt();
            lis[array_id].push_back(elementValue);
        }

        query.exec("DELETE FROM arrays; ALTER TABLE arrays AUTO_INCREMENT = 1;");

        for(int i = 0; i < lis.size();i++){
            if(lis[i].isEmpty()) continue;
            SortingByShellLibrary::sortByShell(lis[i]);
            query.prepare("INSERT INTO arrays (id, name) VALUES (:id, 'sorted');");
            query.bindValue(":id", i);
            query.exec();
            QString po = "INSERT INTO elements (array_id, id, value) VALUES ";
            for(int j = 0; j < lis[i].size();j++){
                if(j != 0){
                    po += ", ";
                }
                po += "(" + std::to_string(i) + ", " + std::to_string(j) + ", " + std::to_string(lis[i][j]) + ")";
            }
            po += ";";
            query.exec(po);
        }
        QJsonObject response;
        response["action"] = "sort_all";
        QJsonDocument doc(response);
        QByteArray data = doc.toJson();
        client->write(data);
    }
    

}

void Server::clientDisconnected() {
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (client) {
        qDebug() << "Client disconnected:" << client->peerAddress().toString();
        client->deleteLater();
    }
}
