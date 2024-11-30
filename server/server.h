#ifndef SERVER_H
#define SERVER_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Server : public QTcpServer
{
    Q_OBJECT
protected:
    void incomingConnection(qintptr socketDescriptor) override;
public:
    Server(QObject *parent = nullptr);
    ~Server();
private:
    QSqlDatabase db;
    bool connectToDatabase();
    void handleClient(QTcpSocket *client);

private slots:
    void readClient();
    void clientDisconnected();
};
#endif // SERVER_H
