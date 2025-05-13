#pragma once

#include <string>

class DMIDrive
{
public:
    DMIDrive()
    {
    }

    ~DMIDrive()
    {
    }

    std::string name;
};

class WMI
{
public:
    static std::string getDrive(int index)
    {
        return "WMI default";
    }

    static std::string getSATADrive(int index)
    {
        return "WMI SATA";
    }

    static std::string getUSBDrive(int index)
    {
        return "WMI USB";
    }
};

class LinuxNativeDriveUtil
{
public:
    static std::string getDrive(int index)
    {
        return "Linux default";
    }

    static std::string getSATADrive(int index)
    {
        return "Linux SATA";
    }

    static std::string getUSBDrive(int index)
    {
        return "Linux USB";
    }
};

class Drive
{
public:
    Drive(std::string driveName)
    {
        _imp.name = driveName;
    }

    virtual ~Drive(void)
    {
    }

    void updateFreeSpace()
    {
    }

    void doQuickSMARTCheck()
    {
    }

    std::string getDriveName()
    {
        return _imp.name;
    }

private:
    DMIDrive _imp;
};

class LinuxSATADrive : public Drive
{
public:
    LinuxSATADrive(std::string driveName) 
        : Drive(driveName)
    {
    }
 
    virtual ~LinuxSATADrive()
    {
    }
};

class LinuxUSBDrive : public Drive
{
public:
    LinuxUSBDrive(std::string driveName) 
        : Drive(driveName)
    {
    }
 
    virtual ~LinuxUSBDrive()
    {
    }
};

class WindowsSATADrive : public Drive
{
public:
    WindowsSATADrive(std::string driveName) 
        : Drive(driveName)
    {
    }
 
    virtual ~WindowsSATADrive()
    {
    }
};

class WindowsUSBDrive : public Drive
{
public:
    WindowsUSBDrive(std::string driveName)
        : Drive(driveName)
    {
    }
 
    virtual ~WindowsUSBDrive()
    {
    }
};
