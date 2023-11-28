
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "settingToolBarWeiget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionsave_triggered();

    void on_actionopen_serial_file_triggered();

    void on_actionabort_triggered();

    void on_sendPushButton_clicked();

private:
    Ui::MainWindow *ui;
    SettingToolBarWeiget* settingToolBarWeiget;
};

#endif // MAINWINDOW_H
