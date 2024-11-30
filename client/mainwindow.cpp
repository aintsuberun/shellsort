#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <QRegularExpression>

bool isValidNumberList(const QString &str) {

    static const QRegularExpression regex(R"(^\s*(-?\d+)(\s*,\s*-?\d+)*\s*$)");
    return regex.match(str).hasMatch();

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QTcpSocket(this))

{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Array", "Information", "Sort", "Update", "Delete"});
    ui->tableWidget->setColumnWidth(1, 210);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    connectToServer();
    on_pushButton_Show_clicked();

    ui->pushButton_Show->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
    socket->disconnectFromHost();
}

void MainWindow::connectToServer() {
    socket->connectToHost("127.0.0.1", 12345);
    if (!socket->waitForConnected(3000)) {
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}



QString convertingTSFL(QList<int> lis){
    QString str;
    if(!lis.empty()) str += std::to_string(lis[0]);
    for(int i = 1; i < lis.size(); i++){
        str += ", " + std::to_string(lis[i]);
    }
    return str;
}

void MainWindow::onReadyRead() {
    // Чтение всех доступных данных из сокета
    QByteArray data = socket->readAll();

    // Преобразуем полученные данные в JSON-документ
    QJsonDocument doc = QJsonDocument::fromJson(data);

    // Проверяем, что полученные данные — это объект JSON
    if (doc.isObject()) {
        QJsonObject response = doc.object();

        // Проверяем, что в ответе есть массив с числами
        if(response["action"] == "get_elements"){
            if (response.contains("elements") && response["elements"].isArray()) {
                QJsonArray elementsArray = response["elements"].toArray();
                QJsonArray arraysArray = response["arrays"].toArray();


                // Заполняем таблицу числами
                int array_id = 1;
                QList <QList<int>> lis;
                QList <QString> isSorted;
                lis.resize(2);
                isSorted.resize(2);
                bool isEmpty = true;
                for(int i = 0; i < arraysArray.size();i++){
                    QJsonObject arrayObject = arraysArray[i].toObject();
                    array_id = arrayObject["id"].toInt();
                    if(array_id + 2 > isSorted.size()){
                        isSorted.resize(array_id + 2);
                    }
                    if(arrayObject["name"].toString() == "sorted"){
                        isSorted[array_id] = "Sorted";
                    }else{
                        isSorted[array_id] = "Not Sorted";
                    }
                }
                array_id = 1;
                for (int i = 0; i < elementsArray.size(); ++i) {
                    QJsonObject elementObject = elementsArray[i].toObject();

                    if(array_id != elementObject["array_id"].toInt()){
                        array_id = elementObject["array_id"].toInt();
                        if(array_id + 2 > lis.size()){
                            lis.resize(array_id + 2);
                        }
                    }

                    lis[array_id].push_back(elementObject["value"].toInt());

                    isEmpty = false;

                }
                ui->tableWidget->setRowCount(0);
                if(isEmpty) return;

                int RowCount = 0;
                for(int i = 0; i < lis.size();i++){
                    if(lis[i].isEmpty()) continue;
                    RowCount++;
                }
                ui->tableWidget->setRowCount(RowCount);

                RowCount = 0;
                for(int i = 0; i < lis.size(); i++){
                    if(lis[i].isEmpty()) continue;
                    RowCount++;

                    QTableWidgetItem *item_id = new QTableWidgetItem(QString::number(i));
                    item_id->setFlags(item_id->flags() & ~Qt::ItemIsEditable);

                    QTableWidgetItem *item_isSorted = new QTableWidgetItem(isSorted[i]);
                    item_isSorted->setFlags(item_isSorted->flags() & ~Qt::ItemIsEditable);
                    
                    QPushButton* buttonSort = new QPushButton("Sort", this);
                    
                    QPushButton* buttonUpdate = new QPushButton("Update", this);

                    QPushButton* buttonDelete = new QPushButton("Delete", this);

                    connect(buttonUpdate, &QPushButton::clicked, this, [this, RowCount]() {
                        UpdateOnButtonClicked(ui->tableWidget->item(RowCount - 1, 0)->text().toInt(), ui->tableWidget->item(RowCount - 1, 1)->text());
                        });

                    connect(buttonSort, &QPushButton::clicked, this, [this, RowCount]() {
                        SortOnButtonClicked(ui->tableWidget->item(RowCount - 1, 0)->text().toInt());
                        });

                    connect(buttonDelete, &QPushButton::clicked, this, [this, RowCount]() {
                        DeleteOnButtonClicked(ui->tableWidget->item(RowCount - 1, 0)->text().toInt());
                        });


                    ui->tableWidget->setItem(RowCount - 1, 0, item_id);
                    ui->tableWidget->setItem(RowCount - 1, 1, new QTableWidgetItem(convertingTSFL(lis[i])));
                    ui->tableWidget->setItem(RowCount - 1, 2, item_isSorted);
                    ui->tableWidget->setCellWidget(RowCount - 1, 3, buttonSort);
                    ui->tableWidget->setCellWidget(RowCount - 1, 4, buttonUpdate);
                    ui->tableWidget->setCellWidget(RowCount - 1, 5, buttonDelete);

                }

            } else {
                qWarning() << "Response does not contain a valid 'elements' array";
            }
        }
        if(response["action"] == "delete_all"){
            ui->tableWidget->setRowCount(0);
        }

        if (response["action"] == "sort_id") {
            on_pushButton_Show_clicked();
        }
        
        if(response["action"] == "insert_elements"){
            on_pushButton_Show_clicked();
        }

        if(response["action"] == "sort_all"){
            on_pushButton_Show_clicked();
        }

        if (response["action"] == "update") {
            on_pushButton_Show_clicked();
        }

        if (response["action"] == "delete_id") {
            on_pushButton_Show_clicked();
        }
        

    } else {
        qWarning() << "Received data is not a valid JSON object";
    }
}

void MainWindow::DeleteOnButtonClicked(int row) {
    if (socket->state() == QTcpSocket::ConnectedState) {

        QJsonObject request;
        request["action"] = "delete_id";
        request["id"] = row;
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }
    else {
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}

void MainWindow::UpdateOnButtonClicked(int row, QString text) {
    if (socket->state() == QTcpSocket::ConnectedState) {

        QJsonObject request;
        request["action"] = "update";
        request["id"] = row;
        QJsonArray elementsArray;

        QStringList strList = text.split(",", Qt::SkipEmptyParts);
        for (int i = 0; i < strList.size(); i++) {
            QJsonObject elementObject;
            elementObject["id"] = i;
            elementObject["value"] = strList[i].toInt();
            elementsArray.append(elementObject);
        }
        request["elements"] = elementsArray;
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }
    else {
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}

void MainWindow::SortOnButtonClicked(int row) {
    if (socket->state() == QTcpSocket::ConnectedState) {

        QJsonObject request;
        request["action"] = "sort_id";
        request["id"] = row;
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }
    else {
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}

void MainWindow::on_pushButton_Add_clicked()
{
    if (socket->state() == QTcpSocket::ConnectedState) {
        QJsonObject request;
        request["action"] = "insert_elements";
        QJsonArray elementsArray;

        QString str = ui->lineEdit->text();
        if(!isValidNumberList(str)){
            QMessageBox::critical(this, "Error", "Data is not valid");
            return;
        }
        QStringList strList = str.split(",", Qt::SkipEmptyParts);
        for(int i = 0; i < strList.size(); i++){
            QJsonObject elementObject;
            elementObject["id"] = i;
            elementObject["value"] =  strList[i].toInt();
            elementsArray.append(elementObject);
        }
        request["elements"] = elementsArray;
        request["array_id"] = -1;
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }else{
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}


void MainWindow::on_pushButton_Delete_clicked()
{
    if (socket->state() == QTcpSocket::ConnectedState) {

        QJsonObject request;
        request["action"] = "delete_all";
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }else{
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}


void MainWindow::on_pushButton_Sort_clicked()
{
    if (socket->state() == QTcpSocket::ConnectedState) {

        QJsonObject request;
        request["action"] = "sort_all";
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }else{
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}

void MainWindow::on_pushButton_Show_clicked()
{
    if (socket->state() == QTcpSocket::ConnectedState) {
        QJsonObject request;
        request["action"] = "get_elements";
        QJsonDocument doc(request);
        socket->write(doc.toJson());
        socket->flush();
    }
}




void MainWindow::on_pushButton_Close_clicked()
{
    this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        dragStart = (event->globalPosition() - frameGeometry().topLeft()).toPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        move((event->globalPosition() - dragStart).toPoint());
}

void MainWindow::on_pushButton_Minimazed_clicked()
{
    QWidget::showMinimized();
}

