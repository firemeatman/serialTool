#ifndef SETTINGTOOLBARWEIGET_H
#define SETTINGTOOLBARWEIGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class SettingToolBarWeiget;
}

class SettingToolBarWeiget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingToolBarWeiget(QWidget *parent = nullptr);
    ~SettingToolBarWeiget();


    int getBaudRate() const;
    void setBaudRate(int newBaudRate);


    QList<QSerialPortInfo> getAvaiablePortList() const;
    void setAvaiablePortList(const QList<QSerialPortInfo> &newAvaiablePortList);
    QSerialPortInfo getCurrentPort() const;
    void setCurrentPort(const QSerialPortInfo &newCurrentPort);

    QSerialPort::DataBits getDataBits() const;
    void setDataBits(const QSerialPort::DataBits &newDataBits);
    QSerialPort::StopBits getStopBit() const;
    void setStopBit(const QSerialPort::StopBits &newStopBit);
    QSerialPort::Parity getVertifyBit() const;
    void setVertifyBit(const QSerialPort::Parity &newVertifyBit);

private:
    Ui::SettingToolBarWeiget *ui;
    int baudRate = 9600;
    QSerialPort::DataBits dataBits = QSerialPort::Data8;
    QSerialPort::StopBits stopBit = QSerialPort::OneStop;
    QSerialPort::Parity vertifyBit = QSerialPort::NoParity;
    QList<QSerialPortInfo> avaiablePortList;
    QSerialPortInfo currentPort;

signals:
    void changed_portSetting();

public slots:
    void _on_select_baudRateComboBox(int index);
    void _on_select_dataBitComboBox(int index);
    void _on_select_stopBitComboBox(int index);
    void _on_select_vertifyBitComboBox(int index);
    void _on_PortComboBox_activated(int index);
    void _on_clicked_refrshButton();

};

inline int SettingToolBarWeiget::getBaudRate() const
{
    return baudRate;
}

inline void SettingToolBarWeiget::setBaudRate(int newBaudRate)
{
    baudRate = newBaudRate;
}



inline QList<QSerialPortInfo> SettingToolBarWeiget::getAvaiablePortList() const
{
    return avaiablePortList;
}

inline void SettingToolBarWeiget::setAvaiablePortList(const QList<QSerialPortInfo> &newAvaiablePortList)
{
    avaiablePortList = newAvaiablePortList;
}

inline QSerialPortInfo SettingToolBarWeiget::getCurrentPort() const
{
    return currentPort;
}

inline void SettingToolBarWeiget::setCurrentPort(const QSerialPortInfo &newCurrentPort)
{
    currentPort = newCurrentPort;
}

inline QSerialPort::DataBits SettingToolBarWeiget::getDataBits() const
{
    return dataBits;
}

inline void SettingToolBarWeiget::setDataBits(const QSerialPort::DataBits &newDataBits)
{
    dataBits = newDataBits;
}

inline QSerialPort::StopBits SettingToolBarWeiget::getStopBit() const
{
    return stopBit;
}

inline void SettingToolBarWeiget::setStopBit(const QSerialPort::StopBits &newStopBit)
{
    stopBit = newStopBit;
}

inline QSerialPort::Parity SettingToolBarWeiget::getVertifyBit() const
{
    return vertifyBit;
}

inline void SettingToolBarWeiget::setVertifyBit(const QSerialPort::Parity &newVertifyBit)
{
    vertifyBit = newVertifyBit;
}

#endif // SETTINGTOOLBARWEIGET_H
