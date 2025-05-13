#include "stdafx.h"
#include "WindowsDriveManager.h"


WindowsDriveManager::WindowsDriveManager(void)
{
}


WindowsDriveManager::~WindowsDriveManager(void)
{
}

Drive* WindowsDriveManager::createDrive(std::string type, int index)
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
