#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T15:28:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_FILE += "myapp.rc.txt"
TARGET = "Phiction Phreak"
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    main_db.cpp \
    com_db.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

DISTFILES +=
