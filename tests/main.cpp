#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QElapsedTimer>
#include <QRandomGenerator>
#include <QCoreApplication>
#include <iostream>



using namespace std;

QList<int> generateUniqueRandomNumbers(int count, int min, int max) {

    QSet<int> uniqueNumbers;
    while (uniqueNumbers.size() < count) {
        int randomNumber = QRandomGenerator::global()->bounded(min, max + 1);
        uniqueNumbers.insert(randomNumber);
    }

    return uniqueNumbers.values();
}

QJsonArray generateRandomArray(int arrayId) {
    QJsonArray elements;
    int size = QRandomGenerator::global()->bounded(1, 10);
    for (int i = 0; i < size; ++i) {
        QJsonObject element;
        element["id"] = i;
        element["value"] = QRandomGenerator::global()->bounded(-50, 50);
        elements.append(element);
    }
    QJsonObject array;
    array["array_id"] = arrayId;
    array["elements"] = elements;
    return elements;
}
bool requestGet_elements_id(QTcpSocket &socket, int id, bool isSorted){
    QJsonObject request;
    request["action"] = "get_elements_id";
    request["id"] = id;

    QJsonDocument doc(request);
    socket.write(doc.toJson());
    socket.flush();
    if (!socket.waitForReadyRead(3000)) {
        cerr << "Timeout while waiting for server response" << endl;
        return false;
    }
    QByteArray responseData = socket.readAll();
    QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);

    if (!responseDoc.isObject() || responseDoc.object()["action"] != "get_elements_id") {
        cerr << "Failed to get array #" << id << endl;
        return false;
    }else{
        if(isSorted){
            cout << "Sorted ";
        }else{
            cout << "Not sorted ";
        }
        cout << "array[" << responseDoc.object()["id"].toInt() << "]: ";
        for(int i = 0; i < responseDoc.object()["elements"].toArray().size(); i++){
            QJsonObject element = responseDoc.object()["elements"].toArray()[i].toObject();
            cout << element["value"].toInt() << " ";
        }
        cout << endl;
    }
    return true;
}
bool testSortArrays(QTcpSocket &socket, int arrayCountToSort, int arrayCountAll) {
    QElapsedTimer timer;
    timer.start();

    QList <int> randomNumbers = generateUniqueRandomNumbers(arrayCountToSort, 1, arrayCountAll);
    for (int i = 0; i < arrayCountToSort; ++i) {

        if(!requestGet_elements_id(socket, randomNumbers[i], false)){
            return false;
        }

        QJsonObject request;
        request["action"] = "sort_id";
        request["id"] = randomNumbers[i];

        QJsonDocument doc(request);
        socket.write(doc.toJson());
        socket.flush();


        if (!socket.waitForReadyRead(3000)) {
            cerr << "Timeout while waiting for server response" << endl;
            return false;
        }

        QByteArray responseData = socket.readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);

        if (!responseDoc.isObject() || responseDoc.object()["action"] != "sort_id") {
            cerr << "Failed to sort array #" << randomNumbers[i] << endl;
            return false;
        }
        if(!requestGet_elements_id(socket, randomNumbers[i], true)){
            return false;
        }
    }

    qint64 elapsed = timer.elapsed();
    cout << "Sorted " << arrayCountToSort << " arrays where " <<  arrayCountAll <<" arrays in " << elapsed << " ms" << endl;
    cout << "Average time to sort 1 array is " << elapsed / 100.0 << " ms" << endl;
    return true;
}

bool requestDelete_all(QTcpSocket &socket, int arrayCount){
    QElapsedTimer timer;
    timer.start();

    QJsonObject request;
    request["action"] = "delete_all";
    QJsonDocument doc(request);
    socket.write(doc.toJson());
    socket.flush();
    if (!socket.waitForReadyRead(3000)) {
        cerr << "Timeout while waiting for server response" << endl;
        return false;
    }
    QByteArray responseData = socket.readAll();
    QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);

    if (!responseDoc.isObject() || responseDoc.object()["action"] != "delete_all") {
        cerr << "No valid response (delete_all)" << endl;
        return false;
    }
    qint64 elapsed = timer.elapsed();
    cout << "Deleted " << arrayCount << " arrays in " << elapsed << " ms" << endl;
    return true;
}

bool testAddArrays(QTcpSocket &socket, int arrayCount) {
    QElapsedTimer timer;
    timer.start();

    for (int i = 0; i < arrayCount; ++i) {
        QJsonObject request;
        request["action"] = "insert_elements";
        request["array_id"] = i + 1;
        request["elements"] = generateRandomArray(i + 1);
        QJsonDocument doc(request);
        socket.write(doc.toJson());
        socket.flush();

        if (!socket.waitForReadyRead(3000)) {
            cerr << "Timeout while waiting for server response" << endl;
            return false;
        }

        QByteArray responseData = socket.readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);

        if (!responseDoc.isObject() || responseDoc.object()["action"] != "insert_elements") {
            cerr << "Failed to add array #" << i + 1 << endl;
            return false;
        }
    }

    qint64 elapsed = timer.elapsed();
    cout << "Added " << arrayCount << " arrays in " << elapsed << " ms" << endl;
    return true;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 12345);

    if (!socket.waitForConnected(3000)) {
        cerr << "Failed to connect to server" << endl;
        return -1;
    }

    if(!requestDelete_all(socket, 0)){
        cerr << "Failed to delete_all in the bigining" << endl;
        return -1;
    }

    cout << "////////////////////////////" << endl;

    cout << "Test adding with 100 arrays..." << endl;
    if (testAddArrays(socket, 100) ) {
        cout << "Test with 100 arrays passed." << endl;
    } else {
        cerr << "Test with 100 arrays failed." << endl;
    }
    cout << "Test sort 100 arrays with 100 arrays..." << endl;
    if(testSortArrays(socket, 100, 100)){
        cout << "Test sorting 100/100 arrays passed." << endl;
    } else {
        cerr << "Test sorting 100/100 arrays failed." << endl;
    }
    cout << "Test delete with 100 arrays..." << endl;
    if(requestDelete_all(socket, 100)){
        cout << "Test delete with 100 arrays passed." << endl;
    } else {
        cerr << "Test delete with 100 arrays failed." << endl;
    }
    cout << "////////////////////////////" << endl;

    cout << "Test adding with 1000 arrays..." << endl;
    if (testAddArrays(socket, 1000)) {
        cout << "Test adding with 1000 arrays passed." << endl;
    } else {
        cerr << "Test adding with 1000 arrays failed." << endl;
    }

    cout << "Test sort 100 arrays with 1000 arrays..." << endl;
    if(testSortArrays(socket, 100, 1000)){
        cout << "Test sorting 100/1000 arrays passed." << endl;
    } else {
        cerr << "Test sorting 100/1000 arrays failed." << endl;
    }
    cout << "Test delete with 1000 arrays..." << endl;
    if(requestDelete_all(socket, 1000)){
        cout << "Test delete with 1000 arrays passed." << endl;
    } else {
        cerr << "Test delete with 1000 arrays failed." << endl;
    }

    cout << "////////////////////////////" << endl;

    cout << "Test adding with 10000 arrays..." << endl;
    if (testAddArrays(socket, 10000)) {
        cout << "Test adding with 10000 passed." << endl;
    } else {
        cerr << "Test adding with 10000 failed." << endl;
    }
    cout << "Test sort 100 arrays with 10000 arrays..." << endl;
    if(testSortArrays(socket, 100, 10000)){
        cout << "Test sorting 100/10000 arrays passed." << endl;
    } else {
        cerr << "Test sorting 100/10000 arrays failed." << endl;
    }
    cout << "Testing delete 10000 arrays..." << endl;
    if (requestDelete_all(socket, 10000)) {
        cout << "Test with delete 10000 arrays passed." << endl;
    } else {
        cerr << "Test with delete 10000 arrays failed." << endl;
    }
    socket.disconnectFromHost();
    return 0;
}
