#include <QApplication>
#include <QMessageBox>
#include <QtSql>
#include "mainwindow.h"
#include "ui_mainwindow.h"

QStringList db_num;
QStringList c_db;

void load_db1(){

    QSqlDatabase db_new = QSqlDatabase::addDatabase("QSQLITE");        
    QString dbPath = qApp->applicationDirPath() + "/phreakDB.db";
    db_new.setDatabaseName(dbPath);
    db_new.open();

    QSqlQuery query;
    if(query.exec("SELECT * FROM words")){
        while(query.next()){
            c_db << query.value(1).toString();
            db_num << query.value(0).toString();
        }

    }
    db_new.close();

}

