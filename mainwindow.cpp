
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QToolBar>
#include <QSerialPort>
#include "common/globalData.h"
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

    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::_on_sendPushButton_clicked);
    connect(global_readThread, &ReadThread::data_entered, this, &MainWindow::_on_data_entered);
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

void MainWindow::_on_sendPushButton_clicked()
{
    qint32 baudRate = settingToolBarWeiget->getBaudRate();
    float stopBit = settingToolBarWeiget->getStopBit();
    int vertifyBit = settingToolBarWeiget->getVertifyBit();
    QString inputText = ui->textEdit_2->toPlainText();
    QSerialPortInfo portInfo = settingToolBarWeiget->getCurrentPort();
    qDebug()<<"波特率:"<<baudRate<<";"<<"停止位:"<<stopBit<<";"<<"校验:"<<vertifyBit<<";"<<"串口:"<<portInfo.portName()<<"\n";
    qDebug()<<"输入:"<<inputText;
    if(portInfo.isNull()){
        return;
    }
    if(serialPort == nullptr){
        serialPort = new QSerialPort(portInfo,this);
    }

    serialPort->setPort(portInfo);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setParity(QSerialPort::NoParity);

    serialPort->write(inputText.toStdString().c_str());
    for (;;) {
        if (serialPort->waitForBytesWritten()){
            break;
        }else{
            break;
        }
    }



}

void MainWindow::_on_data_entered(char* data,int size)
{

}

