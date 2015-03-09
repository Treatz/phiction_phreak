#include <QApplication>
#include <QMessageBox>
#include <QtSql>
#include "mainwindow.h"
#include "ui_mainwindow.h"
QStringList db;

void load_db0(){

    QSqlDatabase db_new = QSqlDatabase::addDatabase("QSQLITE");    
    QString dbPath = qApp->applicationDirPath() + "/phreakDB.db";
    db_new.setDatabaseName(dbPath);
    db_new.open();

    QSqlQuery query;
    if(query.exec("SELECT * FROM phictionphreak")){
        while(query.next()){
            db << query.value(0).toString();
        }

    }
db_new.close();
}
