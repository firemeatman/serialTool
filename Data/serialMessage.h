
#ifndef SERIALMESSAGE_H
#define SERIALMESSAGE_H

#include <QByteArray>
#include <QDateTime>

class SerialMessage
{

typedef enum{
    PC_TO_TARGET = 0,
    TARGET_TO_PC = 1
} TransferDirection;

public:
    SerialMessage();

    int id;
    TransferDirection direction;
    QByteArray content;
    QDateTime date;
};

#endif // SERIALMESSAGE_H
