#include "settingToolBarWeiget.h"
#include "ui_settingToolBarWeige.h"
#include <QDebug>
SettingToolBarWeiget::SettingToolBarWeiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingToolBarWeiget)
{
    ui->setupUi(this);
    this->resize(200,500);
    connect(ui->comboBox,&QComboBox::activated,this,&SettingToolBarWeiget::on_select_baudRateComboBox);
    connect(ui->comboBox_2,&QComboBox::activated,this,&SettingToolBarWeiget::on_select_stopBitComboBox);
    connect(ui->comboBox_3,&QComboBox::activated,this,&SettingToolBarWeiget::on_select_vertifyBitComboBox);
}

SettingToolBarWeiget::~SettingToolBarWeiget()
{
    delete ui;
}

void SettingToolBarWeiget::on_select_baudRateComboBox(int index)
{
    if(index == 0){
        baudRate = 9600;
    }else if(index == 1){
        baudRate = 14400;
    }
}

void SettingToolBarWeiget::on_select_stopBitComboBox(int index)
{
    if(index == 0){
        stopBit = 1;
    }else if(index == 1){
        stopBit = 1.5;
    }else{
        stopBit = 2;
}
}

void SettingToolBarWeiget::on_select_vertifyBitComboBox(int index)
{
    if(index == 0){
        vertifyBit = 0;
    }else if(index == 1){
        vertifyBit = 1;
    }else{
        vertifyBit = 2;
    }
}
