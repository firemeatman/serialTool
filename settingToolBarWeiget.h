#ifndef SETTINGTOOLBARWEIGET_H
#define SETTINGTOOLBARWEIGET_H

#include <QWidget>

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

private:
    Ui::SettingToolBarWeiget *ui;
    int baudRate = 9600;
    float stopBit = 1.0;
    int vertifyBit = 0;

public slots:
    void on_select_baudRateComboBox(int index);
    void on_select_stopBitComboBox(int index);
    void on_select_vertifyBitComboBox(int index);

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

#endif // SETTINGTOOLBARWEIGET_H
