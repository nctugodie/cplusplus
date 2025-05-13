#pragma once

#include "Drive.h"
#include "Process.h"
#include "IOPort.h"

class DMIElementFactory
{
public:
    DMIElementFactory(void);
    virtual ~DMIElementFactory(void);
    virtual Drive* createDrive(std::string type, int index) = 0;
    virtual Process* createProcess(int id) = 0;
    virtual IOPort* createIOPort(int address) = 0;
};

