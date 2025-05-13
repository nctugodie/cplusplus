#pragma once
#include "drivemanager.h"
class LinuxDriveManager :
    public DriveManager
{
public:
    LinuxDriveManager(void);
    virtual ~LinuxDriveManager(void);

protected:
    virtual Drive* createDrive(std::string type, int index);
};

