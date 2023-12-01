
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
    void safe_lockTask();
    void safe_unlockTask();

    bool getIs_open() const;
    void setIs_open(bool newIs_open);

signals:
    void data_entered(QByteArray* data,int size);

private:
    char* dataBuffer;
    int bufferSize;
    QSerialPort* port;
    bool is_open = false;
    QMutex taskMutex;

};

#endif // READTHREAD_H
