#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

void MainWindow::on_onOff_pushButton_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
      manager->get(QNetworkRequest(QUrl("http://172.20.10.2/p")));
}

void MainWindow::on_selectMode_pushButton_clicked()
{
    int newMode = ui->mode_comboBox->currentIndex();

    if(newMode < currentMode)
    {
        for(int i = currentMode; i < 5; i++)
        {
            qDebug() << "m";
        }
        currentMode = 0;
    }

    for(int i = currentMode; i < newMode; i++)
    {
        qDebug() << "m";
    }

    currentMode = newMode;
}
