
#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
#include <QSerialPort>


class ReadThread : public QThread
{
    Q_OBJECT
public:
    explicit ReadThread(QObject *parent = nullptr, char* dataBuffer = nullptr, int bufferSize = 0, QSerialPort* port = nullptr);
    void run() override;


    QSerialPort *getPort() const;
    void setPort(QSerialPort *newPort);

signals:
    void data_entered(char* data,int size);

private:
    char* dataBuffer;
    int bufferSize;
    QSerialPort* port;

};

#endif // READTHREAD_H
