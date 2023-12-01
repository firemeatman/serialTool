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

    void _on_data_entered(QByteArray* data,int size);
public slots:
    void _on_changed_portSetting();
    void _on_select_data_codeComboBox(int index);
    void _on_select_send_codeComboBox(int index);

private:
    Ui::WorkCentralWedgit *ui;
    SettingToolBarWeiget* settingToolBarWeiget = nullptr;
    QSerialPort* serialPort = nullptr;
    QByteArray sendStr;
    QByteArray recvStr;
    QList<QByteArray> sendHistory;
    QList<QByteArray> recvHistory;



};

#endif // WORKCENTRALWEDGIT_H
