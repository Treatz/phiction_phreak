#include <QMessageBox>
#include <QStringList>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)), this, SLOT(my_search(QUrl)));
      load_db1();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::on_search(int choose)
{








        if(choose==0){
            QString load = " Loading...";
            ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
            ui->textBrowser->setHtml( load );
            QApplication::processEvents();


        int total=0;
        QString input =   ui->lineEdit->text();
        QStringList slist = input.split(" ");
            for(int l=0; l<slist.size(); l++){
                        slist[l].prepend(" ");
                        slist[l].append(" ");
            }
        QString myString = "";
           for(int i=0; i<db.count()-1; i++){
               int counter=0;
              for(int b=0; b<slist.size(); b++){
            int start = db[i].indexOf(slist.at(b), 0, Qt::CaseInsensitive);
            if(start!=-1)
                counter++;

              }

            if(counter>=slist.size()){

                QStringList winkle = db[i].split(" ");
                for(int l=1; l<winkle.size(); l++){
                    winkle[l].prepend(" ");
                    winkle[l].append(" ");
                myString.append("<a href=\"");
                myString.append(winkle[l]);
                myString.append("\" STYLE=\"font-size: 13pt; color:black; text-decoration: none\">");
                myString.append(winkle[l]);
                myString.append("</a> ");

                }
                myString.append("<br />");
                winkle.clear();
                total++;

            }
           }
           QString Text = " Total Results: ";
           Text.append(QString::number(total));
           Text.append("<br /><br />");
           Text.append(myString);
           ui->textBrowser->clear();
           ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
           ui->textBrowser->setHtml( Text );
        //   connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)), this, SLOT(my_search(QUrl)));
    }
   if(choose==1){
       QString load = " Loading...";
       ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
       ui->textBrowser->setHtml( load );
       QApplication::processEvents();

       int total = 0;
       QString myString = "";       
       for(int i=0; i<db.count()-1; i++){

           QStringList winkle = db[i].split(" ");
           for(int l=1; l<winkle.size(); l++){
               winkle[l].prepend(" ");
               winkle[l].append(" ");
           myString.append("<a href=\"");
           myString.append(winkle[l]);
           myString.append("\" STYLE=\"font-size: 13pt; color:black; text-decoration: none\">");
           myString.append(winkle[l]);
           myString.append("</a> ");

           }
           myString.append("<br />");
           total++;
           winkle.clear();

       }
       QString Text = " Total Results: ";
       Text.append(QString::number(total));
       Text.append("<br /><br />");
       Text.append(myString);


       ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
       ui->textBrowser->setHtml( Text );


   }
return 0;
}

void MainWindow::on_pushButton_clicked()
{

on_search(0);

}

void MainWindow::on_pushButton_2_clicked()
{
    on_search(1);

}

void MainWindow::on_pushButton_3_clicked()
{




    QString load = " Loading...";
    ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
    ui->textBrowser->setHtml( load );
    QApplication::processEvents();

    QString myString = "<table>";
    int total = 0;
    for(int i=0; i<=c_db.count()-1; i++){
     myString.append("<tr><td><a href=\"");
     myString.append(c_db[i]);
     myString.append("\" STYLE=\"font-size: 13pt; font-weight: lighter; color:black; text-decoration: none\">");
     myString.append(c_db[i]);
     myString.append("</a></td><td>");     
     myString.append(db_num[i]);
     myString.append("</td></tr>");
     total++;          
    }

    QString Text = " Total Results: ";
    Text.append(QString::number(total));
    Text.append("</table></span><br /><br />");
    Text.append(myString);
    ui->textBrowser->clear();    
    ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
      ui->textBrowser->setHtml( Text );
   //   connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)), this, SLOT(my_search(QUrl)));
}

void MainWindow::on_actionContact_triggered()
{
    QMessageBox msgBox;
        msgBox.setTextFormat(Qt::RichText); // this does the magic trick and allows you to click the link
        msgBox.setText("Made by Corey White (2015)<br/> <br /><a href=\"http://www.streetwitch.com\">http://www.streetwitch.com</a><br/><br/>Released For Free.");

        msgBox.setIconPixmap(QPixmap(":/icon.png"));
        msgBox.exec();

}

void MainWindow::my_search(const QUrl &url){




        QString load = " Loading...";
        ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
        ui->textBrowser->setHtml( load );
        QApplication::processEvents();


        int total=0;
        QString input = url.toString();

        QString myString = "";

           for(int i=0; i<db.count()-1; i++){


if((db[i].indexOf(input, 0, Qt::CaseInsensitive))!=-1)
{
                QStringList ripvan = db[i].split(" ");
                for(int l=1; l<ripvan.size(); l++){
                    ripvan[l].prepend(" ");
                    ripvan[l].append(" ");
                myString.append("<a href=\"");
                myString.append(ripvan[l]);
                myString.append("\" STYLE=\"font-size: 13pt; color:black; text-decoration: none\">");
                myString.append(ripvan[l]);
                myString.append("</a> ");

                }
                myString.append("<br />");
                total++;
                ripvan.clear();
            }

              }





           QString Text = " Total Results: ";
           Text.append(QString::number(total));
           Text.append("<br /><br />");
           Text.append(myString);
           ui->textBrowser->clear();
           ui->textBrowser->setStyleSheet("font: 13pt \"Courier\";");
           ui->textBrowser->setHtml( Text );
        //   connect(ui->textBrowser, SIGNAL(anchorClicked(QUrl)), this, SLOT(my_search(QUrl)));

}


void MainWindow::on_lineEdit_returnPressed()
{
   on_search(0);
}
