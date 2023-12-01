#include "workCentralWedgit.h"
#include "ui_workCentralWedgit.h"

#include <QToolBar>
#include <QSerialPort>
#include "../../common/globalData.h"


WorkCentralWedgit::WorkCentralWedgit(QWidget *parent, SettingToolBarWeiget* settingToolBar) :
    QWidget(parent),
    ui(new Ui::WorkCentralWedgit)
{
    ui->setupUi(this);
    settingToolBarWeiget = settingToolBar;
    connect(ui->sendButton, &QPushButton::clicked, this, &WorkCentralWedgit::_on_sendPushButton_clicked);
    connect(global_readThread, &ReadThread::data_entered, this, &WorkCentralWedgit::_on_data_entered);
    connect(settingToolBarWeiget, &SettingToolBarWeiget::changed_portSetting, this, &WorkCentralWedgit::_on_changed_portSetting);
    connect(ui->encodeComboBox_1, &QComboBox::activated, this, &WorkCentralWedgit::_on_select_data_codeComboBox);
    connect(ui->encodeComboBox_2, &QComboBox::activated, this, &WorkCentralWedgit::_on_select_send_codeComboBox);
}

WorkCentralWedgit::~WorkCentralWedgit()
{
    delete ui;
}



void WorkCentralWedgit::_on_sendPushButton_clicked()
{
    if(this->serialPort == nullptr){
        return;
    }
    QString inputText = ui->sendTextEdit->toPlainText();
    serialPort->write(inputText.toStdString().c_str());
    bool flag;
    for (;;) {
        flag = serialPort->waitForBytesWritten();
    }
    if(flag){
        ui->recvTextEdit->append("\n\r[you]:");
        ui->recvTextEdit->append(inputText);
    }


}

void WorkCentralWedgit::_on_data_entered(QByteArray* data,int size)
{
    data[size] = 0;
    ui->recvTextEdit->append("\n\r[target]:");
    ui->recvTextEdit->append(QString(*data));
    delete data;
}

void WorkCentralWedgit::_on_changed_portSetting()
{
    qint32 baudRate = settingToolBarWeiget->getBaudRate();
    QSerialPort::DataBits dataBits = settingToolBarWeiget->getDataBits();
    QSerialPort::StopBits stopBit = settingToolBarWeiget->getStopBit();
    QSerialPort::Parity vertifyBit = settingToolBarWeiget->getVertifyBit();
    QSerialPortInfo portInfo = settingToolBarWeiget->getCurrentPort();
    qDebug()<<"波特率:"<<baudRate<<";"<<"停止位:"<<stopBit<<";"<<"校验:"<<vertifyBit<<";"<<"串口:"<<portInfo.portName()<<"\n";

        if(portInfo.isNull()){
        return;
    }
    global_readThread->safe_lockTask();
    if(this->serialPort == nullptr){
        this->serialPort = new QSerialPort(portInfo,this);
        global_readThread->setPort(this->serialPort);
    }
    serialPort->setPort(portInfo);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBit);
    serialPort->setParity(vertifyBit);
    global_readThread->safe_unlockTask();
}

void WorkCentralWedgit::_on_select_data_codeComboBox(int index)
{
    if(index == 0){

    }else if(index == 1){

    }else if(index == 2){

    }
}

void WorkCentralWedgit::_on_select_send_codeComboBox(int index)
{

}


