// CommandPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Server.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
    ICommand* doorOpenCmd = new RemoteDoorCommand(new RemoteDoor("open"));
    Result doorOpenResult = doorOpenCmd->Execute();
    assert(Result::CRITICAL == doorOpenResult.getStatus());
    assert(0 == doorOpenResult.getMessage().compare("door open"));
    delete doorOpenCmd;

    ICommand* doorCloseCmd = new RemoteDoorCommand(new RemoteDoor("not open"));
    Result doorCloseResult = doorCloseCmd->Execute();
    assert(Result::OK == doorCloseResult.getStatus());
    assert(true == doorCloseResult.getMessage().empty());
    delete doorCloseCmd;

    Server server;
    doorOpenCmd = new RemoteDoorCommand(new RemoteDoor("open"));
    server.AddCommand(doorOpenCmd);
    server.Monitor();

	return 0;
}

