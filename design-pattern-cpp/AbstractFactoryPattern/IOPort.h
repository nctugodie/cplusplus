#pragma once

#include <string>

class IOPort
{
public:
    IOPort(std::string name, int address)
    {
        _name = name;
        _address = address;
    }

    virtual ~IOPort()
    {
    }

    std::string getName()
    {
        return _name;
    }

    int getAddress()
    {
        return _address;
    }

private:
    std::string _name;
    int _address;
};

class WindowsIOPort : public IOPort
{
public:
    WindowsIOPort(int address)
        : IOPort("windows io port", address)
    {
    }

    virtual ~WindowsIOPort()
    {
    }
};

class LinuxIOPort : public IOPort
{
public:
    LinuxIOPort(int address)
        : IOPort("linux io port", address)
    {
    }

    virtual ~LinuxIOPort()
    {
    }
};
