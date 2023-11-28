#ifndef SETTINGTOOLBARWEIGET_H
#define SETTINGTOOLBARWEIGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPortInfo>

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

    float getStopBit() const;
    void setStopBit(float newStopBit);

    int getVertifyBit() const;
    void setVertifyBit(int newVertifyBit);

    QList<QSerialPortInfo> getAvaiablePortList() const;
    void setAvaiablePortList(const QList<QSerialPortInfo> &newAvaiablePortList);
    QSerialPortInfo getCurrentPort() const;
    void setCurrentPort(const QSerialPortInfo &newCurrentPort);

private:
    Ui::SettingToolBarWeiget *ui;
    int baudRate = 9600;
    float stopBit = 1.0;
    int vertifyBit = 0;
    QList<QSerialPortInfo> avaiablePortList;
    QSerialPortInfo currentPort;

public slots:
    void _on_select_baudRateComboBox(int index);
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

inline float SettingToolBarWeiget::getStopBit() const
{
    return stopBit;
}

inline void SettingToolBarWeiget::setStopBit(float newStopBit)
{
    stopBit = newStopBit;
}

inline int SettingToolBarWeiget::getVertifyBit() const
{
    return vertifyBit;
}

inline void SettingToolBarWeiget::setVertifyBit(int newVertifyBit)
{
    vertifyBit = newVertifyBit;
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

#endif // SETTINGTOOLBARWEIGET_H
