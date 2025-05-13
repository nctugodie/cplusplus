#pragma once
#include "dmielementfactory.h"
class WindowsDMIElementFactory :
    public DMIElementFactory
{
public:
    WindowsDMIElementFactory(void);
    virtual ~WindowsDMIElementFactory(void);

    virtual Drive* createDrive(std::string type, int index);
    virtual Process* createProcess(int id);
    virtual IOPort* createIOPort(int address);
};

