#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStringList>
#include <QMainWindow>
void load_db0();
void load_db1();
extern QStringList db_num;
extern QStringList c_db;
extern QStringList db;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionContact_triggered();

    void on_lineEdit_returnPressed();

    int on_search(int choose);

     void my_search(const QUrl &url);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
