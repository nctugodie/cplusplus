#include "stdafx.h"
#include "DriveManager.h"


DriveManager::DriveManager(void)
{
}

DriveManager::~DriveManager(void)
{
}

Drive* DriveManager::getDrive(std::string type, int index)
{
    Drive* drive = createDrive(type, index);
    drive->updateFreeSpace();
    drive->doQuickSMARTCheck();

    return drive;
}
