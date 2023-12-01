
#include "readThread.h"
#include "../common/safe_memcpy.h"

ReadThread::ReadThread(QObject *parent, char* dataBuffer, int bufferSize, QSerialPort* port)
    : QThread{parent}
{
    this->dataBuffer = dataBuffer;
    this->bufferSize = bufferSize;
    this->port = port;
    if(this->dataBuffer == nullptr){
        this->dataBuffer = (char*)malloc(50);
    }
}

ReadThread::~ReadThread()
{
    if(!this->dataBuffer){
        free(this->dataBuffer);
    }

}

void ReadThread::run()
{
    int numRead = 0, numReadTotal = 0;
    char buffer[50];
    while(1){
        this->taskMutex.lock();
        if(!this->is_open){
            this->taskMutex.unlock();
            sleep(100);
            continue;
        }
        for (;;) {
            if(!port){
                sleep(100);
                continue;
            }
            numRead  = port->read(buffer, 50);
            numReadTotal += numRead;
            if (numRead == 0 && !port->waitForReadyRead(500)){
                if(numReadTotal != 0){
                    emit this->data_entered(new QByteArray(buffer), numReadTotal);
                }
                 break;
            }
        }
        this->taskMutex.unlock();
    }

}

QSerialPort *ReadThread::getPort() const
{
    return port;
}

void ReadThread::setPort(QSerialPort *newPort)
{
    //portMutex.lock();
    port = newPort;
    //portMutex.unlock();
}

void ReadThread::safe_lockTask()
{
    this->taskMutex.lock();
}

void ReadThread::safe_unlockTask()
{
    this->taskMutex.unlock();
}

bool ReadThread::getIs_open() const
{
    return is_open;
}

void ReadThread::setIs_open(bool newIs_open)
{
    this->taskMutex.lock();
    is_open = newIs_open;
    this->taskMutex.unlock();
}

