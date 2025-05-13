#include "stdafx.h"
#include "WindowsDMIElementFactory.h"


WindowsDMIElementFactory::WindowsDMIElementFactory(void)
{
}


WindowsDMIElementFactory::~WindowsDMIElementFactory(void)
{
}

Drive* WindowsDMIElementFactory::createDrive(std::string type, int index)
{
    Drive* drive = NULL;

    if (type.compare("SATA") == 0)
    {
        drive = new WindowsSATADrive(WMI::getSATADrive(index));
        printf("create windows sata drive\n");
    }
    else if (type.compare("USB") == 0)
    {
        drive = new WindowsUSBDrive(WMI::getUSBDrive(index));
        printf("create windows usb drive\n");
    }
    else
    {
        printf("not support this windows drive type. %s.\n", type.c_str());
    }

    return drive;
}

Process* WindowsDMIElementFactory::createProcess(int id)
{
    printf("create windows process\n");
    return new WindowsProcess(id);
}

IOPort* WindowsDMIElementFactory::createIOPort(int address)
{
    printf("create windows io port\n");
    return new WindowsIOPort(address);
}

