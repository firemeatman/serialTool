
#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QMutex>

class ReadThread : public QThread
{
    Q_OBJECT
public:
    explicit ReadThread(QObject *parent = nullptr, char* dataBuffer = nullptr, int bufferSize = 50, QSerialPort* port = nullptr);
    ~ReadThread();
    void run() override;


    QSerialPort *getPort() const;
    void setPort(QSerialPort *newPort);

signals:
    void data_entered(char* data,int size);

private:
    char* dataBuffer;
    int bufferSize;
    QSerialPort* port;
    QMutex portMutex;

};

#endif // READTHREAD_H
