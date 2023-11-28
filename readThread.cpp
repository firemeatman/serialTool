
#include "readThread.h"

ReadThread::ReadThread(QObject *parent, char* dataBuffer, int bufferSize, QSerialPort* port)
    : QThread{parent}
{
    this->dataBuffer = dataBuffer;
    this->bufferSize = bufferSize;
    this->port = port;
}

void ReadThread::run()
{
    int numRead = 0, numReadTotal = 0;
    char buffer[50];
    while(1){
        for (;;) {
            numRead  = port->read(buffer, 50);

            // Do whatever with the array

            numReadTotal += numRead;
            if (numRead == 0 && !port->waitForReadyRead(500))
                break;
        }
    }

}

QSerialPort *ReadThread::getPort() const
{
    return port;
}

void ReadThread::setPort(QSerialPort *newPort)
{
    port = newPort;
}

