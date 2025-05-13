// FactoryMetohdPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WindowsDriveManager.h"
#include "LinuxDriveManager.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
    WindowsDriveManager dm;

    Drive* drive = dm.getDrive("USB", 0);
    assert(0 == drive->getDriveName().compare("WMI USB"));
    assert(0 != drive->getDriveName().compare("WMI default"));
    assert(0 != drive->getDriveName().compare("WMI SATA"));
    assert(0 != drive->getDriveName().compare("Linux USB"));
    assert(0 != drive->getDriveName().compare("Linux default"));
    assert(0 != drive->getDriveName().compare("Linux SATA"));
    delete drive;

    drive = dm.getDrive("SAS", 0);
    assert(NULL == drive);
    delete drive;

	return 0;
}

