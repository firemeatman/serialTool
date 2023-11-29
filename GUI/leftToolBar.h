#ifndef LEFTTOOLBAR_H
#define LEFTTOOLBAR_H

#include <QWidget>

namespace Ui {
class LeftToolBar;
}

class LeftToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit LeftToolBar(QWidget *parent = nullptr);
    ~LeftToolBar();

private:
    Ui::LeftToolBar *ui;
};

#endif // LEFTTOOLBAR_H
