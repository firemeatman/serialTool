#pragma once
#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "../IO/readThread.h"
#include "../Data/serialMessage.h"
extern ReadThread* global_readThread;
extern QList<SerialMessage> global_msgList;

#endif // GLOBALDATA_H
