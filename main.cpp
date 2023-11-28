
#include "mainwindow.h"

#include <QApplication>
#include "common/globalData.h"
void init();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    init();
    w.show();
    return a.exec();
}

void init(){
    char* buff = (char*)malloc(50);
    ReadThread* readThread =  new ReadThread(nullptr,buff,50,nullptr);
    readThread->start();

    global_readThread = readThread;
}


