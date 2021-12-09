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

    void on_edit_pushButton_clicked();

    void on_up_pushButton_clicked();

    void on_down_pushButton_clicked();

    void on_left_pushButton_clicked();

    void on_right_pushButton_3_clicked();

    void on_recharge_pushButton_clicked();

    void on_mode_pushButton_clicked();

    void on_super_pushButton_clicked();

    void on_play_pushButton_clicked();

    void dialogFinished();

    void on_schedule_pushButton_clicked();

    void playSchedule();

private:
    Ui::MainWindow *ui;
    int currentMode = 0;
    QString scheduledRoutine;
    void sendData(QString command);
    void playRoutine();
    void listRoutines();
};

#endif // MAINWINDOW_H
