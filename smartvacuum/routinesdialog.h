#ifndef ROUTINESDIALOG_H
#define ROUTINESDIALOG_H

#include <QDialog>
#include <QMap>

namespace Ui {
class RoutinesDialog;
}

class RoutinesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoutinesDialog(QWidget *parent = nullptr);
    ~RoutinesDialog();
    void writeRoutine();
    void readRoutine();
    void listRoutines();

private slots:
    void on_onOff_pushButton_clicked();

    void on_createEdit_pushButton_clicked();

    void on_routine_comboBox_currentIndexChanged(const QString &value);

    void on_delete_pushButton_clicked();

    void on_up_pushButton_clicked();

    void on_down_pushButton_clicked();

    void on_left_pushButton_clicked();

    void on_right_pushButton_3_clicked();

    void on_recharge_pushButton_clicked();

    void on_mode_pushButton_clicked();

    void on_super_pushButton_clicked();

    void on_addTime_pushButton_clicked();

    void on_remove_pushButton_clicked();

private:
    Ui::RoutinesDialog *ui;
    //QStringList commands;
    //bool editing;
    //QVariantMap<QString, QStringList> routines;
};

#endif // ROUTINESDIALOG_H
