
#include "readThread.h"
#include "common/safe_memcpy.h"

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
        for (;;) {
            portMutex.lock();
            if(!port){
                portMutex.unlock();
                sleep(100);
                continue;
            }
            numRead  = port->read(buffer, 50);
            numReadTotal += numRead;
            if (numRead == 0 && !port->waitForReadyRead(500)){
                if(numReadTotal != 0){
                    safe_memcpy(dataBuffer, buffer, numReadTotal, dataBuffer, ((char*)dataBuffer)+bufferSize);
                    emit this->data_entered(buffer, numReadTotal);
                }
                portMutex.unlock();
                 break;
            }
            portMutex.unlock();
        }
    }

}

QSerialPort *ReadThread::getPort() const
{
    return port;
}

void ReadThread::setPort(QSerialPort *newPort)
{
    portMutex.lock();
    port = newPort;
    portMutex.unlock();
}

