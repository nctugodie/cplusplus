#include "stdafx.h"
#include "LinuxDriveManager.h"


LinuxDriveManager::LinuxDriveManager(void)
{
}


LinuxDriveManager::~LinuxDriveManager(void)
{
}


Drive* LinuxDriveManager::createDrive(std::string type, int index)
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
