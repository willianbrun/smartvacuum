#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

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
    void on_onOff_pushButton_clicked();

    void replyFinished(QNetworkReply *);

    void on_selectMode_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    int currentMode = 0;
    void sendData(QString command);
};

#endif // MAINWINDOW_H
