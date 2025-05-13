#pragma once
#include "drivemanager.h"
class WindowsDriveManager :
    public DriveManager
{
public:
    WindowsDriveManager(void);
    virtual ~WindowsDriveManager(void);

protected:
    virtual Drive* createDrive(std::string type, int index);
};

