#ifndef WORKCENTRALWEDGIT_H
#define WORKCENTRALWEDGIT_H

#include <QWidget>
#include "settingToolBarWeiget.h"
namespace Ui {
class WorkCentralWedgit;
}

class WorkCentralWedgit : public QWidget
{
    Q_OBJECT

public:
    explicit WorkCentralWedgit(QWidget *parent = nullptr, SettingToolBarWeiget* settingToolBar = nullptr);
    ~WorkCentralWedgit();

private slots:

    void _on_sendPushButton_clicked();

    void _on_data_entered(char* data,int size);
public slots:
    void _on_changed_portSetting();

private:
    Ui::WorkCentralWedgit *ui;
    SettingToolBarWeiget* settingToolBarWeiget = nullptr;
    QSerialPort* serialPort = nullptr;


};

#endif // WORKCENTRALWEDGIT_H
