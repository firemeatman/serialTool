
#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QToolBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* rightToolBar = new QToolBar(this);
    settingToolBarWeiget = new SettingToolBarWeiget(this);
    rightToolBar->addWidget(settingToolBarWeiget);
    rightToolBar->setAllowedAreas(Qt::RightToolBarArea);
    this->addToolBar(Qt::RightToolBarArea,rightToolBar);

    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendPushButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionsave_triggered()
{

}


void MainWindow::on_actionopen_serial_file_triggered()
{

}


void MainWindow::on_actionabort_triggered()
{

}

void MainWindow::on_sendPushButton_clicked()
{
    int baudRate = settingToolBarWeiget->getBaudRate();
    float stopBit = settingToolBarWeiget->getStopBit();
    int vertifyBit = settingToolBarWeiget->getVertifyBit();
    QString inputText = ui->textEdit_2->toPlainText();
    qDebug()<<"波特率:"<<baudRate<<";"<<"停止位:"<<stopBit<<";"<<"校验:"<<vertifyBit<<"\n";
    qDebug()<<"输入:"<<inputText;
}

