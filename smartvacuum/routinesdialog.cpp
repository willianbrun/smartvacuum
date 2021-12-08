#include "routinesdialog.h"
#include "ui_routinesdialog.h"

#include <QSettings>

RoutinesDialog::RoutinesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoutinesDialog)
{
    ui->setupUi(this);
    listRoutines();
}

RoutinesDialog::~RoutinesDialog()
{
    delete ui;
}

void RoutinesDialog::writeRoutine(){
    QSettings sett;
    sett.beginGroup("Routines");
    QStringList commands;

    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        commands.append(ui->listWidget->item(i)->text());
    }
    sett.setValue(ui->name_lineEdit->text(), commands);

    if(ui->routine_comboBox->currentText() != "Criar nova" && ui->routine_comboBox->currentText() != ui->name_lineEdit->text())
    {
       sett.remove(ui->routine_comboBox->currentText());
    }

    sett.endGroup();
}

void RoutinesDialog::readRoutine(){
    QSettings sett;
    sett.beginGroup("Routines");
    ui->listWidget->clear();
    QStringList commands = sett.value(ui->routine_comboBox->currentText()).value<QStringList>();
    ui->listWidget->clear();
    ui->listWidget->addItems(commands);
    sett.endGroup();

}

void RoutinesDialog::listRoutines(){
    QSettings sett;
    sett.beginGroup("Routines");
    ui->routine_comboBox->clear();
    ui->routine_comboBox->addItem("Criar nova");
    ui->routine_comboBox->addItems(sett.childKeys());
    sett.endGroup();
}

void RoutinesDialog::on_createEdit_pushButton_clicked()
{
    writeRoutine();
    listRoutines();
    ui->routine_comboBox->setCurrentIndex(0);
}

void RoutinesDialog::on_routine_comboBox_currentIndexChanged(const QString &value)
{
    if(value == "Criar nova")
    {
        ui->name_lineEdit->setText("");
        ui->createEdit_pushButton->setText("Criar");
        ui->delete_pushButton->setEnabled(false);
    }
    else
    {
        ui->name_lineEdit->setText(value);
        ui->createEdit_pushButton->setText("Salvar");
        ui->delete_pushButton->setEnabled(true);
        readRoutine();
    }
}

void RoutinesDialog::on_delete_pushButton_clicked()
{
    QSettings sett;
    sett.beginGroup("Routines");
    sett.remove(ui->routine_comboBox->currentText());
    sett.endGroup();
    listRoutines();
    ui->routine_comboBox->setCurrentIndex(0);
}

void RoutinesDialog::on_onOff_pushButton_clicked()
{
    ui->listWidget->addItem("Liga/Desliga");
}

void RoutinesDialog::on_up_pushButton_clicked()
{
    ui->listWidget->addItem("Frente");
}

void RoutinesDialog::on_down_pushButton_clicked()
{
    ui->listWidget->addItem("Atrás");
}

void RoutinesDialog::on_left_pushButton_clicked()
{
    ui->listWidget->addItem("Esquerda");
}

void RoutinesDialog::on_right_pushButton_3_clicked()
{
    ui->listWidget->addItem("Direita");
}

void RoutinesDialog::on_recharge_pushButton_clicked()
{
    ui->listWidget->addItem("Recarga");
}

void RoutinesDialog::on_mode_pushButton_clicked()
{
    ui->listWidget->addItem("Modo");
}

void RoutinesDialog::on_super_pushButton_clicked()
{
    ui->listWidget->addItem("Super");
}

void RoutinesDialog::on_addTime_pushButton_clicked()
{
    ui->listWidget->addItem(QString("Aguardar %1").arg(ui->spinBox->text()));
}

void RoutinesDialog::on_remove_pushButton_clicked()
{
    QListWidgetItem *it = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete it;
}
