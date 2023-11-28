
#include "common/globalData.h"
#include "mainwindow.h"
#include <QApplication>

void init();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    init();
    MainWindow w;
    w.show();
    return a.exec();
}

void init(){
    char* buff = (char*)malloc(50);
    ReadThread* readThread =  new ReadThread(nullptr,buff,50,nullptr);
    readThread->start();

    global_readThread = readThread;
}


