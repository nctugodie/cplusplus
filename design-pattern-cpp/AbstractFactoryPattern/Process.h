#pragma once

#include <string>

class Process
{
public:
    Process(std::string name, int id)
    {
        _name = name;
        _id = id;
    }

    virtual ~Process()
    {
    }

    std::string getName()
    {
        return _name;
    }

    int getId()
    {
        return _id;
    }

private:
    std::string _name;
    int _id;
};

class WindowsProcess : public Process
{
public:
    WindowsProcess(int id)
        : Process("windows process", id)
    {
    }

    virtual ~WindowsProcess()
    {
    }
};

class LinuxProcess : public Process
{
public:
    LinuxProcess(int id)
        : Process("linux process", id)
    {
    }

    virtual ~LinuxProcess()
    {
    }
};

