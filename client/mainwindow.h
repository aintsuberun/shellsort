#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMouseEvent>
#include <QJsonDocument>
#include <QJsonObject>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_pushButton_Show_clicked();
    void onReadyRead();
    
    void on_pushButton_Add_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_Sort_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_Minimazed_clicked();

    void SortOnButtonClicked(int row);

    void UpdateOnButtonClicked(int row, QString text);

    void DeleteOnButtonClicked(int row);

private:
    QPoint dragStart;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    void connectToServer();
    
};
#endif // MAINWINDOW_H
