#pragma once

#include <string>

class Result
{
public:
    enum
    {
        OK = 1,
        WARNING = 2,
        CRITICAL = 3
    };

public:
    Result()
    {
        _message = "";
        _status = OK;
    }

    ~Result()
    {
    }

    std::string getMessage()
    {
        return _message;
    }

    int getStatus()
    {
        return _status;
    }

    void setMessgage(const char* message)
    {
        _message = message;
    }

    void setStatus(int status)
    {
        _status = status;
    }

private:
    std::string _message;
    int _status;
};

class ICommand
{
public:
    ICommand(void);
    virtual ~ICommand(void);

    virtual Result Execute() = 0;
};
