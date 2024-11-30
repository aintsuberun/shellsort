/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton_Show;
    QPushButton *pushButton_Close;
    QPushButton *pushButton_Minimazed;
    QGroupBox *groupBox_Table;
    QLabel *label_Update;
    QLabel *label_Delete_Id;
    QLabel *label_Id;
    QLabel *label_Array;
    QLabel *label_Info;
    QLabel *label_Sort_Id;
    QGroupBox *groupBox_Buttons;
    QLabel *label_LineEdit;
    QPushButton *pushButton_Add;
    QLabel *label__Sort_All;
    QLineEdit *lineEdit;
    QPushButton *pushButton_Delete;
    QLabel *label_Delete_All;
    QPushButton *pushButton_Sort;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 650);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(246, 228, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(250, 241, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(123, 114, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(164, 152, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(123, 114, 127, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(120, 230, 731, 341));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        tableWidget->setFont(font);
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        tableWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: 1px solid black;\n"
"    outline: none;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    border: none;\n"
"}\n"
""));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(false);
        tableWidget->setGridStyle(Qt::PenStyle::SolidLine);
        pushButton_Show = new QPushButton(centralwidget);
        pushButton_Show->setObjectName("pushButton_Show");
        pushButton_Show->setGeometry(QRect(50, 10, 80, 24));
        pushButton_Close = new QPushButton(centralwidget);
        pushButton_Close->setObjectName("pushButton_Close");
        pushButton_Close->setGeometry(QRect(930, 0, 41, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(240, 28, 56, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(255, 135, 151, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(247, 81, 103, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(120, 14, 28, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(160, 19, 37, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(247, 141, 155, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush15(QColor(120, 14, 28, 127));
        brush15.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        QBrush brush16(QColor(255, 87, 109, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush16);
        pushButton_Close->setPalette(palette1);
        pushButton_Minimazed = new QPushButton(centralwidget);
        pushButton_Minimazed->setObjectName("pushButton_Minimazed");
        pushButton_Minimazed->setGeometry(QRect(880, 0, 45, 25));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        pushButton_Minimazed->setFont(font1);
        groupBox_Table = new QGroupBox(centralwidget);
        groupBox_Table->setObjectName("groupBox_Table");
        groupBox_Table->setGeometry(QRect(490, 40, 351, 171));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(11);
        font2.setItalic(true);
        font2.setUnderline(false);
        groupBox_Table->setFont(font2);
        groupBox_Table->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid black;\n"
"	background-color: rgb(238, 255, 252);\n"
"    outline: none;\n"
"}\n"
"\n"
"QGroupBox::item {\n"
"    border: none;\n"
"}"));
        label_Update = new QLabel(groupBox_Table);
        label_Update->setObjectName("label_Update");
        label_Update->setGeometry(QRect(10, 110, 351, 41));
        label_Update->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font3.setPointSize(10);
        label_Update->setFont(font3);
        label_Update->setAutoFillBackground(false);
        label_Update->setTextFormat(Qt::TextFormat::AutoText);
        label_Update->setScaledContents(false);
        label_Update->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_Update->setWordWrap(true);
        label_Delete_Id = new QLabel(groupBox_Table);
        label_Delete_Id->setObjectName("label_Delete_Id");
        label_Delete_Id->setGeometry(QRect(10, 150, 331, 20));
        label_Delete_Id->setFont(font3);
        label_Id = new QLabel(groupBox_Table);
        label_Id->setObjectName("label_Id");
        label_Id->setGeometry(QRect(10, 10, 301, 20));
        label_Id->setFont(font3);
        label_Array = new QLabel(groupBox_Table);
        label_Array->setObjectName("label_Array");
        label_Array->setGeometry(QRect(10, 30, 131, 20));
        label_Array->setFont(font3);
        label_Info = new QLabel(groupBox_Table);
        label_Info->setObjectName("label_Info");
        label_Info->setGeometry(QRect(10, 40, 341, 51));
        label_Info->setFont(font3);
        label_Info->setWordWrap(true);
        label_Sort_Id = new QLabel(groupBox_Table);
        label_Sort_Id->setObjectName("label_Sort_Id");
        label_Sort_Id->setGeometry(QRect(10, 90, 321, 20));
        label_Sort_Id->setFont(font3);
        groupBox_Buttons = new QGroupBox(centralwidget);
        groupBox_Buttons->setObjectName("groupBox_Buttons");
        groupBox_Buttons->setGeometry(QRect(130, 40, 341, 171));
        groupBox_Buttons->setFont(font2);
        groupBox_Buttons->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid black;\n"
"	background-color: rgb(238, 255, 252);\n"
"    outline: none;\n"
"}\n"
"\n"
"QGroupBox::item {\n"
"    border: none;\n"
"}"));
        label_LineEdit = new QLabel(groupBox_Buttons);
        label_LineEdit->setObjectName("label_LineEdit");
        label_LineEdit->setGeometry(QRect(10, 10, 231, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font4.setPointSize(10);
        font4.setItalic(false);
        label_LineEdit->setFont(font4);
        pushButton_Add = new QPushButton(groupBox_Buttons);
        pushButton_Add->setObjectName("pushButton_Add");
        pushButton_Add->setGeometry(QRect(210, 30, 80, 24));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush17(QColor(87, 113, 130, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush17);
        QBrush brush18(QColor(130, 170, 195, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush18);
        QBrush brush19(QColor(108, 141, 162, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush19);
        QBrush brush20(QColor(43, 57, 65, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush20);
        QBrush brush21(QColor(58, 75, 87, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush21);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush22(QColor(171, 184, 192, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush21);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush19);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush21);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush23(QColor(43, 57, 65, 127));
        brush23.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        QBrush brush24(QColor(113, 147, 169, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush24);
        pushButton_Add->setPalette(palette2);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setUnderline(false);
        pushButton_Add->setFont(font5);
        label__Sort_All = new QLabel(groupBox_Buttons);
        label__Sort_All->setObjectName("label__Sort_All");
        label__Sort_All->setGeometry(QRect(100, 80, 231, 20));
        label__Sort_All->setFont(font3);
        lineEdit = new QLineEdit(groupBox_Buttons);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 30, 181, 24));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font6.setPointSize(11);
        lineEdit->setFont(font6);
        pushButton_Delete = new QPushButton(groupBox_Buttons);
        pushButton_Delete->setObjectName("pushButton_Delete");
        pushButton_Delete->setGeometry(QRect(10, 130, 80, 24));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush18);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::Accent, brush24);
        pushButton_Delete->setPalette(palette3);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font7.setPointSize(11);
        font7.setBold(false);
        pushButton_Delete->setFont(font7);
        label_Delete_All = new QLabel(groupBox_Buttons);
        label_Delete_All->setObjectName("label_Delete_All");
        label_Delete_All->setGeometry(QRect(100, 130, 201, 21));
        label_Delete_All->setFont(font3);
        pushButton_Sort = new QPushButton(groupBox_Buttons);
        pushButton_Sort->setObjectName("pushButton_Sort");
        pushButton_Sort->setGeometry(QRect(10, 80, 80, 24));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush18);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush19);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush20);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush21);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush22);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette4.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush18);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush19);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush20);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush21);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush18);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush19);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush20);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::Accent, brush24);
        pushButton_Sort->setPalette(palette4);
        pushButton_Sort->setFont(font7);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Show->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_Minimazed->setText(QCoreApplication::translate("MainWindow", "__", nullptr));
        groupBox_Table->setTitle(QString());
        label_Update->setText(QCoreApplication::translate("MainWindow", "Update - \320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205 \320\262 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\274 (\320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\274) \320\274\320\260\321\201\321\201\320\270\320\262\320\265", nullptr));
        label_Delete_Id->setText(QCoreApplication::translate("MainWindow", "Delete - \320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \320\274\320\260\321\201\321\201\320\270\320\262\320\260", nullptr));
        label_Id->setText(QCoreApplication::translate("MainWindow", "ID - \320\235\320\276\320\274\320\265\321\200 \320\274\320\260\321\201\321\201\320\270\320\262\320\260 \320\262 \320\261\320\260\320\267\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_Array->setText(QCoreApplication::translate("MainWindow", "Array - \320\234\320\260\321\201\321\201\320\270\320\262", nullptr));
        label_Info->setText(QCoreApplication::translate("MainWindow", "Information - \320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\274\320\260\321\201\321\201\320\270\320\262\320\260 (\320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271/\320\275\320\265\320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271)", nullptr));
        label_Sort_Id->setText(QCoreApplication::translate("MainWindow", "Sort - \320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \320\274\320\260\321\201\321\201\320\270\320\262\320\260", nullptr));
        groupBox_Buttons->setTitle(QString());
        label_LineEdit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\213 \320\274\320\260\321\201\321\201\320\270\320\262\320\260:", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label__Sort_All->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \320\262\321\201\320\265\321\205 \320\274\320\260\321\201\321\201\320\270\320\262\320\276\320\262", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_Delete_All->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\321\201\320\265\321\205 \320\274\320\260\321\201\321\201\320\270\320\262\320\276\320\262", nullptr));
        pushButton_Sort->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
