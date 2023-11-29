#include "leftToolBar.h"
#include "ui_leftToolBar.h"

LeftToolBar::LeftToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftToolBar)
{
    ui->setupUi(this);
}

LeftToolBar::~LeftToolBar()
{
    delete ui;
}
