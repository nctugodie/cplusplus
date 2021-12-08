// AbstractFactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SystemManager.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
    {
        WindowsDMIElementFactory windows_factory;
        SystemManager sm(&windows_factory);
        Drive* drive = sm.getDrive("USB", 0);
        Process* process = sm.getProcess(3388);
        IOPort* io_port = sm.getIOPort(0x00FF);
        assert(0 == drive->getDriveName().compare("WMI USB"));
        assert(0 == process->getName().compare("windows process"));
        assert(3388 == process->getId());
        assert(0 == io_port->getName().compare("windows io port"));
        assert(0x00FF == io_port->getAddress());
        delete drive;
        delete process;
        delete io_port;
    }

    {
        LinuxDMIElementFactory linux_factory;
        SystemManager sm(&linux_factory);
        Drive* drive = sm.getDrive("USB", 0);
        Process* process = sm.getProcess(3388);
        IOPort* io_port = sm.getIOPort(0x00FF);
        assert(0 == drive->getDriveName().compare("Linux USB"));
        assert(0 == process->getName().compare("linux process"));
        assert(3388 == process->getId());
        assert(0 == io_port->getName().compare("linux io port"));
        assert(0x00FF == io_port->getAddress());
        delete drive;
        delete process;
        delete io_port;
    }

	return 0;
}

