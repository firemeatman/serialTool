#include "settingToolBarWeiget.h"
#include "ui_settingToolBarWeige.h"
#include <QDebug>
#include <QToolButton>
SettingToolBarWeiget::SettingToolBarWeiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingToolBarWeiget)
{
    ui->setupUi(this);
    this->resize(200,500);
    connect(ui->comboBox,&QComboBox::activated,this,&SettingToolBarWeiget::_on_select_baudRateComboBox);
    connect(ui->dataBitComboBox,&QComboBox::activated,this,&SettingToolBarWeiget::_on_select_dataBitComboBox);
    connect(ui->comboBox_2,&QComboBox::activated,this,&SettingToolBarWeiget::_on_select_stopBitComboBox);
    connect(ui->comboBox_3,&QComboBox::activated,this,&SettingToolBarWeiget::_on_select_vertifyBitComboBox);
    connect(ui->portComboBox,&QComboBox::activated,this,&SettingToolBarWeiget::_on_PortComboBox_activated);
    connect(ui->refrshButton,&QAbstractButton::clicked,this,&SettingToolBarWeiget::_on_clicked_refrshButton);
}

SettingToolBarWeiget::~SettingToolBarWeiget()
{
    delete ui;
}

void SettingToolBarWeiget::_on_select_baudRateComboBox(int index)
{
    if(index == 0){
        baudRate = 9600;
    }else if(index == 1){
        baudRate = 14400;
    }
    emit this->changed_portSetting();
}

void SettingToolBarWeiget::_on_select_dataBitComboBox(int index)
{
    if(index == 0){
        dataBits = QSerialPort::Data8;
    }else if(index == 1){
        dataBits = QSerialPort::Data7;
    }else{
        dataBits = QSerialPort::Data6;
    }
    emit this->changed_portSetting();
}

void SettingToolBarWeiget::_on_select_stopBitComboBox(int index)
{
    if(index == 0){
        stopBit = QSerialPort::OneStop;
    }else if(index == 1){
        stopBit = QSerialPort::OneAndHalfStop;
    }else{
        stopBit = QSerialPort::TwoStop;
    }
    emit this->changed_portSetting();
}

void SettingToolBarWeiget::_on_select_vertifyBitComboBox(int index)
{
    if(index == 0){
        vertifyBit = QSerialPort::NoParity;
    }else if(index == 1){
        vertifyBit = QSerialPort::EvenParity;
    }else{
        vertifyBit = QSerialPort::OddParity;
    }
    emit this->changed_portSetting();
}

void SettingToolBarWeiget::_on_PortComboBox_activated(int index)
{
    if(index > avaiablePortList.size() - 1){
        return;
    }
    currentPort = avaiablePortList[index];
    emit this->changed_portSetting();

}

void SettingToolBarWeiget::_on_clicked_refrshButton()
{
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    avaiablePortList = serialPortInfos;
    int size = ui->portComboBox->count();
    for(int i=size-1;i>=0;i--){
        ui->portComboBox->removeItem(i);
    }
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
        ui->portComboBox->addItem(portInfo.portName());
    }
    if(!avaiablePortList.isEmpty()){
        currentPort = avaiablePortList[0];
        emit this->changed_portSetting();
    }


}
