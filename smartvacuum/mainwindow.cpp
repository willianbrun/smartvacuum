#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "routinesdialog.h"
#include <QNetworkAccessManager>
#include <QDebug>
#include <QSettings>
#include <QThread>
#include <QTimer>

//IP Created by ESP32 to connect with this program
QString ip = "http://172.20.10.2";

QMap<QString, QString> commandNames{{"Liga/Desliga", "p"} , {"Frente", "u"}, {"Atrás", "down"}, {"Esquerda", "left"}, {"Direita", "r"},
                                    {"Recarga", "recharge"}, {"Modo", "mode"}, {"Super", "super"}};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->history_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    listRoutines();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function used to connect and send data to ESP32
void MainWindow::sendData(QString command)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(QString("%1/%2").arg(ip, command))));

    qDebug() << "Sent command: ";
    qDebug() << command;

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("hh:mm:ss");

    ui->history_tableWidget->insertRow(0);
    ui->history_tableWidget->setItem(0, 0, new QTableWidgetItem(commandNames.key(command)));
    ui->history_tableWidget->setItem(0, 1, new QTableWidgetItem(formattedTime));
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

void MainWindow::playRoutine(){
    QSettings sett;
    sett.beginGroup("Routines");
    QStringList commands = sett.value(ui->routine_comboBox->currentText()).value<QStringList>();

    for(int i = 0; i < commands.count(); i++)
    {
        if(commands.at(i).indexOf(QString("Aguardar ")) == 0)
        {
            QThread::sleep(QString(commands[i]).mid(9).toInt());
        }

        else if(commands.at(i) == "Liga/Desliga")
        {
            on_onOff_pushButton_clicked();
        }

        else if(commands.at(i) == "Modo")
        {
            on_mode_pushButton_clicked();
        }

        else
        {
            sendData(commandNames[commands.at(i)]);
        }

    }
    sett.endGroup();
}

void MainWindow::listRoutines(){
    QSettings sett;
    sett.beginGroup("Routines");
    ui->routine_comboBox->clear();
    ui->routine_comboBox->addItems(sett.childKeys());
    sett.endGroup();
}

void MainWindow::dialogFinished(){
    listRoutines();
}

void MainWindow::playSchedule() {
    int index = ui->routine_comboBox->findText(scheduledRoutine);
    ui->routine_comboBox->setCurrentIndex(index);
    on_play_pushButton_clicked();
    ui->schedule_label->setText("Nenhuma rotina agendada");
}

void MainWindow::on_selectMode_pushButton_clicked()
{
    int newMode = ui->mode_comboBox->currentIndex();

    if(newMode < currentMode)
    {
        for(int i = currentMode; i < 5; i++)
        {
            sendData("mode");
        }
        currentMode = 0;
    }

    for(int i = currentMode; i < newMode; i++)
    {
        sendData("mode");
    }

    currentMode = newMode;
    QString text = ui->mode_comboBox->itemText(currentMode);
    ui->currentMode_label->setText(QString("Modo atual: %1").arg(text));
}

void MainWindow::on_edit_pushButton_clicked()
{
    RoutinesDialog *dlg = new RoutinesDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();
    QObject::connect(dlg, SIGNAL(finished(int)), this, SLOT(dialogFinished()));
}

void MainWindow::on_onOff_pushButton_clicked()
{
    sendData("p");
    currentMode = 0;
    QString text = ui->mode_comboBox->itemText(currentMode);
    ui->currentMode_label->setText(QString("Modo atual: %1").arg(text));
}

void MainWindow::on_up_pushButton_clicked()
{
    sendData("u");
}

void MainWindow::on_down_pushButton_clicked()
{
    sendData("down");
}

void MainWindow::on_left_pushButton_clicked()
{
    sendData("left");
}

void MainWindow::on_right_pushButton_3_clicked()
{
    sendData("r");
}

void MainWindow::on_recharge_pushButton_clicked()
{
    sendData("recharge");
}

void MainWindow::on_mode_pushButton_clicked()
{
    sendData("mode");

    if((currentMode + 1) == 5)
        currentMode = 0;
    else
        currentMode++;

    QString text = ui->mode_comboBox->itemText(currentMode);
    ui->currentMode_label->setText(QString("Modo atual: %1").arg(text));
}

void MainWindow::on_super_pushButton_clicked()
{
    sendData("super");
}

void MainWindow::on_play_pushButton_clicked()
{
    playRoutine();
}

void MainWindow::on_schedule_pushButton_clicked()
{

    scheduledRoutine = ui->routine_comboBox->currentText();
    QDateTime then = QDateTime::currentDateTime();
    auto setTime = ui->schedule_timeEdit->time();

    if(then.time() > setTime){
        then = then.addDays(1);
    }
    then.setTime(setTime);


    int diff = QDateTime::currentDateTime().msecsTo(then);

    QTimer::singleShot(diff, this, SLOT(playSchedule()));

    ui->schedule_label->setText(QString("%1 às %2").arg(scheduledRoutine, setTime.toString("hh:mm")));
}
