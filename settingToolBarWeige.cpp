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
}

void SettingToolBarWeiget::_on_select_stopBitComboBox(int index)
{
    if(index == 0){
        stopBit = 1;
    }else if(index == 1){
        stopBit = 1.5;
    }else{
        stopBit = 2;
}
}

void SettingToolBarWeiget::_on_select_vertifyBitComboBox(int index)
{
    if(index == 0){
        vertifyBit = 0;
    }else if(index == 1){
        vertifyBit = 1;
    }else{
        vertifyBit = 2;
    }
}

void SettingToolBarWeiget::_on_PortComboBox_activated(int index)
{
    if(index > avaiablePortList.size() - 1){
        return;
    }
    currentPort = avaiablePortList[index];

}

void SettingToolBarWeiget::_on_clicked_refrshButton()
{
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    avaiablePortList = serialPortInfos;
    ui->portComboBox->addItem("COM1");
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
}
