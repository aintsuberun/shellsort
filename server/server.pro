QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# LIBS += -L"C:\Users\ilia\Desktop\SortByInsert\SortingByInsertLibrary\build\Desktop_Qt_6_8_0_MSVC2022_64bit-Release\release" -lSortingByInsertLibrary

# INCLUDEPATH += "C:\Users\ilia\Desktop\SortByInsert\SortingByInsertLibrary"

SOURCES += \
    main.cpp \
    server.cpp \
    sortingByShellLibrary.cpp

HEADERS += \
    SortingByShellLibrary.h \
    SortingByShellLibrary_global.h \
    server.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
