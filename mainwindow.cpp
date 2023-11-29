
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QToolBar>
#include "GUI/workWindow/workCentralWedgit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* rightToolBar = new QToolBar(this);
    settingToolBarWeiget = new SettingToolBarWeiget(this);
    rightToolBar->addWidget(settingToolBarWeiget);
    rightToolBar->setAllowedAreas(Qt::RightToolBarArea);
    this->addToolBar(Qt::RightToolBarArea,rightToolBar);

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


