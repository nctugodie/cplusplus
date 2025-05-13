#pragma once

#include "WindowsDMIElementFactory.h"
#include "LinuxDMIElementFactory.h"

class SystemManager
{
public:
    SystemManager(DMIElementFactory* factory)
    {
        _factory = factory;
    }

    ~SystemManager()
    {
        _factory = NULL;
    }

    Drive* getDrive(std::string type, int index)
    {
        Drive* drive = _factory->createDrive(type, index);
        drive->updateFreeSpace();
        drive->doQuickSMARTCheck();

        return drive;
    }

    Process* getProcess(int id)
    {
        return _factory->createProcess(id);
    }

    IOPort* getIOPort(int address)
    {
        return _factory->createIOPort(address);
    }

private:
    DMIElementFactory* _factory;
};