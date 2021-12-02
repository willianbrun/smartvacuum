#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>

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

void MainWindow::on_onOffpushButton_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
      manager->get(QNetworkRequest(QUrl("http://172.20.10.2/p")));
}
