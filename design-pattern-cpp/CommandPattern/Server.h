#pragma once

#include <vector>
#include "RemoteDoor.h"


class Server
{
public:
    Server()
    {
    }

    ~Server()
    {
    }

    void Monitor()
    {
        for (const auto iter : _commands)
        {
            Result result = iter->Execute();
            if (Result::OK != result.getStatus())
            {
                printf("Server found an issue: %s\n", result.getMessage().c_str());
            }
        }
    }

    void SendAlert()
    {
    }

    void AddCommand(ICommand* cmd)
    {
        _commands.push_back(cmd);
    }

    void RemoveCommand(ICommand* cmd)
    {
    }

private:
    std::vector<ICommand*> _commands;
};