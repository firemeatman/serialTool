
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QToolBar>
#include <QDockWidget>
#include "GUI/workWindow/workCentralWedgit.h"
#include "GUI/leftToolBar.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LeftToolBar* leftToolBarWedgit = new LeftToolBar(this);
    QToolBar* leftToolBar = new QToolBar(this);
    leftToolBar->addWidget(leftToolBarWedgit);
    leftToolBar->setAllowedAreas(Qt::LeftToolBarArea);
    leftToolBar->setMovable(false);
    this->addToolBar(Qt::LeftToolBarArea,leftToolBar);

    settingToolBarWeiget = new SettingToolBarWeiget(this);
    QDockWidget* rightSerialSetting = new QDockWidget(this);
    rightSerialSetting->setWidget(settingToolBarWeiget);
    rightSerialSetting->setAllowedAreas(Qt::RightDockWidgetArea|Qt::LeftDockWidgetArea);
    rightSerialSetting->setFeatures(QDockWidget::DockWidgetFloatable);
    this->addDockWidget(Qt::RightDockWidgetArea,rightSerialSetting);

    WorkCentralWedgit* workCentralWedgit = new WorkCentralWedgit(this, settingToolBarWeiget);
    this->setCentralWidget(workCentralWedgit);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionsave_triggered()
{

}


void MainWindow::on_actionopen_serial_file_triggered()
{

}


void MainWindow::on_actionabort_triggered()
{

}


