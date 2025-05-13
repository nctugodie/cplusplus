#include "stdafx.h"
#include "LinuxDMIElementFactory.h"


LinuxDMIElementFactory::LinuxDMIElementFactory(void)
{
}


LinuxDMIElementFactory::~LinuxDMIElementFactory(void)
{
}

Drive* LinuxDMIElementFactory::createDrive(std::string type, int index)
{
    Drive* drive = NULL;

    if (type.compare("SATA") == 0)
    {
        drive = new LinuxSATADrive(LinuxNativeDriveUtil::getSATADrive(index));
        printf("create linux sata drive\n");
    }
    else if (type.compare("USB") == 0)
    {
        drive = new LinuxSATADrive(LinuxNativeDriveUtil::getUSBDrive(index));
        printf("create linux usb drive\n");
    }
    else
    {
        printf("not support this linux drive type. %s.", type.c_str());
    }

    return drive;
}

Process* LinuxDMIElementFactory::createProcess(int id)
{
    printf("create linux process\n");
    return new LinuxProcess(id);
}

IOPort* LinuxDMIElementFactory::createIOPort(int address)
{
    printf("create linux io port\n");
    return new LinuxIOPort(address);
}

