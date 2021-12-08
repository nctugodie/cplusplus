#pragma once

#include "Drive.h"
#include <string>

class DriveManager
{
public:
    DriveManager(void);
    virtual ~DriveManager(void);

    Drive* getDrive(std::string type, int index);

protected:
    virtual Drive* createDrive(std::string type, int index) = 0;
};

