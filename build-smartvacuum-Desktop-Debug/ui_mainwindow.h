/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *recharge_pushButton;
    QPushButton *right_pushButton_3;
    QPushButton *mode_pushButton;
    QPushButton *up_pushButton;
    QPushButton *down_pushButton;
    QPushButton *onOff_pushButton;
    QPushButton *super_pushButton;
    QLabel *label;
    QPushButton *left_pushButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *mode_comboBox;
    QPushButton *selectMode_pushButton;
    QLabel *label_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QComboBox *recording_comboBox;
    QLabel *label_6;
    QPushButton *edit_pushButton;
    QPushButton *play_pushButton;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QPushButton *selectRecording_pushButton;
    QDateTimeEdit *schedule_dateTimeEdit;
    QLabel *label_2;
    QLabel *selected_label;
    QPushButton *selectCommand_pushButton;
    QPushButton *schedule_pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *history_tableWidget;
    QWidget *tab_2;
    QTableWidget *scheduled_tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1023, 458);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(90, 50, 191, 290));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        recharge_pushButton = new QPushButton(gridLayoutWidget);
        recharge_pushButton->setObjectName(QString::fromUtf8("recharge_pushButton"));
        recharge_pushButton->setAutoFillBackground(false);

        gridLayout->addWidget(recharge_pushButton, 8, 0, 1, 1);

        right_pushButton_3 = new QPushButton(gridLayoutWidget);
        right_pushButton_3->setObjectName(QString::fromUtf8("right_pushButton_3"));

        gridLayout->addWidget(right_pushButton_3, 6, 0, 1, 1);

        mode_pushButton = new QPushButton(gridLayoutWidget);
        mode_pushButton->setObjectName(QString::fromUtf8("mode_pushButton"));

        gridLayout->addWidget(mode_pushButton, 9, 0, 1, 1);

        up_pushButton = new QPushButton(gridLayoutWidget);
        up_pushButton->setObjectName(QString::fromUtf8("up_pushButton"));

        gridLayout->addWidget(up_pushButton, 3, 0, 1, 1);

        down_pushButton = new QPushButton(gridLayoutWidget);
        down_pushButton->setObjectName(QString::fromUtf8("down_pushButton"));

        gridLayout->addWidget(down_pushButton, 4, 0, 1, 1);

        onOff_pushButton = new QPushButton(gridLayoutWidget);
        onOff_pushButton->setObjectName(QString::fromUtf8("onOff_pushButton"));
        onOff_pushButton->setAutoDefault(false);

        gridLayout->addWidget(onOff_pushButton, 2, 0, 1, 1);

        super_pushButton = new QPushButton(gridLayoutWidget);
        super_pushButton->setObjectName(QString::fromUtf8("super_pushButton"));

        gridLayout->addWidget(super_pushButton, 10, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        left_pushButton = new QPushButton(gridLayoutWidget);
        left_pushButton->setObjectName(QString::fromUtf8("left_pushButton"));

        gridLayout->addWidget(left_pushButton, 5, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(360, 50, 221, 82));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        mode_comboBox = new QComboBox(gridLayoutWidget_2);
        mode_comboBox->addItem(QString());
        mode_comboBox->addItem(QString());
        mode_comboBox->addItem(QString());
        mode_comboBox->addItem(QString());
        mode_comboBox->addItem(QString());
        mode_comboBox->setObjectName(QString::fromUtf8("mode_comboBox"));

        gridLayout_2->addWidget(mode_comboBox, 1, 0, 1, 1);

        selectMode_pushButton = new QPushButton(gridLayoutWidget_2);
        selectMode_pushButton->setObjectName(QString::fromUtf8("selectMode_pushButton"));

        gridLayout_2->addWidget(selectMode_pushButton, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(660, 50, 301, 111));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        recording_comboBox = new QComboBox(gridLayoutWidget_3);
        recording_comboBox->setObjectName(QString::fromUtf8("recording_comboBox"));

        gridLayout_3->addWidget(recording_comboBox, 1, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        edit_pushButton = new QPushButton(gridLayoutWidget_3);
        edit_pushButton->setObjectName(QString::fromUtf8("edit_pushButton"));

        gridLayout_3->addWidget(edit_pushButton, 3, 0, 1, 1);

        play_pushButton = new QPushButton(gridLayoutWidget_3);
        play_pushButton->setObjectName(QString::fromUtf8("play_pushButton"));

        gridLayout_3->addWidget(play_pushButton, 2, 0, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(360, 170, 221, 181));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        selectRecording_pushButton = new QPushButton(gridLayoutWidget_4);
        selectRecording_pushButton->setObjectName(QString::fromUtf8("selectRecording_pushButton"));

        gridLayout_4->addWidget(selectRecording_pushButton, 5, 0, 1, 1);

        schedule_dateTimeEdit = new QDateTimeEdit(gridLayoutWidget_4);
        schedule_dateTimeEdit->setObjectName(QString::fromUtf8("schedule_dateTimeEdit"));

        gridLayout_4->addWidget(schedule_dateTimeEdit, 7, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLineWidth(1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 3, 0, 1, 1);

        selected_label = new QLabel(gridLayoutWidget_4);
        selected_label->setObjectName(QString::fromUtf8("selected_label"));
        selected_label->setAlignment(Qt::AlignCenter);
        selected_label->setWordWrap(true);

        gridLayout_4->addWidget(selected_label, 6, 0, 1, 1);

        selectCommand_pushButton = new QPushButton(gridLayoutWidget_4);
        selectCommand_pushButton->setObjectName(QString::fromUtf8("selectCommand_pushButton"));

        gridLayout_4->addWidget(selectCommand_pushButton, 4, 0, 1, 1);

        schedule_pushButton = new QPushButton(gridLayoutWidget_4);
        schedule_pushButton->setObjectName(QString::fromUtf8("schedule_pushButton"));

        gridLayout_4->addWidget(schedule_pushButton, 9, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(660, 180, 301, 171));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        history_tableWidget = new QTableWidget(tab);
        if (history_tableWidget->columnCount() < 2)
            history_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        history_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        history_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        history_tableWidget->setObjectName(QString::fromUtf8("history_tableWidget"));
        history_tableWidget->setGeometry(QRect(0, 0, 301, 181));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(history_tableWidget->sizePolicy().hasHeightForWidth());
        history_tableWidget->setSizePolicy(sizePolicy);
        history_tableWidget->setFrameShape(QFrame::StyledPanel);
        history_tableWidget->setAlternatingRowColors(false);
        history_tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        scheduled_tableWidget = new QTableWidget(tab_2);
        if (scheduled_tableWidget->columnCount() < 2)
            scheduled_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        scheduled_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        scheduled_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        scheduled_tableWidget->setObjectName(QString::fromUtf8("scheduled_tableWidget"));
        scheduled_tableWidget->setGeometry(QRect(0, 0, 301, 141));
        sizePolicy.setHeightForWidth(scheduled_tableWidget->sizePolicy().hasHeightForWidth());
        scheduled_tableWidget->setSizePolicy(sizePolicy);
        scheduled_tableWidget->setFrameShape(QFrame::StyledPanel);
        scheduled_tableWidget->setAlternatingRowColors(false);
        scheduled_tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1023, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Vacuum", nullptr));
#ifndef QT_NO_TOOLTIP
        recharge_pushButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        recharge_pushButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        recharge_pushButton->setText(QApplication::translate("MainWindow", "Recarga", nullptr));
        right_pushButton_3->setText(QApplication::translate("MainWindow", "Direita", nullptr));
        mode_pushButton->setText(QApplication::translate("MainWindow", "Modo", nullptr));
        up_pushButton->setText(QApplication::translate("MainWindow", "Frente", nullptr));
        down_pushButton->setText(QApplication::translate("MainWindow", "Atr\303\241s", nullptr));
        onOff_pushButton->setText(QApplication::translate("MainWindow", "Liga/Desliga", nullptr));
        super_pushButton->setText(QApplication::translate("MainWindow", "Super", nullptr));
        label->setText(QApplication::translate("MainWindow", "Comandos", nullptr));
        left_pushButton->setText(QApplication::translate("MainWindow", "Esquerda", nullptr));
        mode_comboBox->setItemText(0, QApplication::translate("MainWindow", "Autolimpeza", nullptr));
        mode_comboBox->setItemText(1, QApplication::translate("MainWindow", "Limpeza especial", nullptr));
        mode_comboBox->setItemText(2, QApplication::translate("MainWindow", "Limpeza aleat\303\263ria", nullptr));
        mode_comboBox->setItemText(3, QApplication::translate("MainWindow", "Limpeza em bordas e cantos", nullptr));
        mode_comboBox->setItemText(4, QApplication::translate("MainWindow", "Limpeza zigue-zague", nullptr));

        selectMode_pushButton->setText(QApplication::translate("MainWindow", "Selecionar", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Selecionar modo de opera\303\247\303\243o", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Executar grava\303\247\303\243o", nullptr));
        edit_pushButton->setText(QApplication::translate("MainWindow", "Editar/criar grava\303\247\303\265es", nullptr));
        play_pushButton->setText(QApplication::translate("MainWindow", "Executar", nullptr));
        selectRecording_pushButton->setText(QApplication::translate("MainWindow", "Selecionar grava\303\247\303\243o", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Programar comando ou grava\303\247\303\243o", nullptr));
        selected_label->setText(QApplication::translate("MainWindow", "Nenhum comando/grava\303\247\303\243o selecionado", nullptr));
        selectCommand_pushButton->setText(QApplication::translate("MainWindow", "Selecionar comando", nullptr));
        schedule_pushButton->setText(QApplication::translate("MainWindow", "Agendar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = history_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Comando", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = history_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Hor\303\241rio", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Hist\303\263rico", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = scheduled_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Comando", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = scheduled_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Hor\303\241rio", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Programado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
