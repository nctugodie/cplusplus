#pragma once

#include "ICommand.h"

class RemoteDoor
{
public:
    RemoteDoor(const char* doorStatus)
        : _doorStatus(doorStatus)
    {
    }

    virtual ~RemoteDoor()
    {
    }

    virtual std::string getDoorStatus()
    {
        return _doorStatus;
    }

private:
    std::string _doorStatus;
};

class MockRemoteDoor : public RemoteDoor
{
public:
    MockRemoteDoor(const char* doorStatus)
        : RemoteDoor(doorStatus)
    {
    }

    virtual ~MockRemoteDoor()
    {
    }
};

class RemoteDoorCommand : public ICommand
{
public:
    RemoteDoorCommand(RemoteDoor* door)
    {
        _door = door;
    }

    virtual ~RemoteDoorCommand()
    {
        if (_door)
            delete _door;
    }

    Result Execute()
    {
        Result result;
        if (_door->getDoorStatus().compare("open") == 0)
        {
            result.setMessgage("door open");
            result.setStatus(Result::CRITICAL);
        }

        return result;
    }

private:
    RemoteDoor* _door;
};

