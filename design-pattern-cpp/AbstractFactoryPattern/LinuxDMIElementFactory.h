#pragma once
#include "dmielementfactory.h"
class LinuxDMIElementFactory :
    public DMIElementFactory
{
public:
    LinuxDMIElementFactory(void);
    virtual ~LinuxDMIElementFactory(void);

    virtual Drive* createDrive(std::string type, int index);
    virtual Process* createProcess(int id);
    virtual IOPort* createIOPort(int address);
};

