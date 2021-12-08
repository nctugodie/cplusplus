// StrategyPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Strategy.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
    Player* player;
    IBatStrategy* strategy;

    strategy = new FreeBatStrategy();
    player = new Player(strategy);
    player->bat();
    delete strategy;
    delete player;

    strategy = new HomeRunStrategy();
    player = new Player(strategy);
    player->bat();
    delete strategy;
    delete player;

    strategy = new BuntStrategy();
    player = new Player(strategy);
    player->bat();
    delete strategy;
    delete player;

    strategy = new SacrificeFlyStrategy();
    player = new Player(strategy);
    player->bat();
    delete strategy;
    delete player;

    return 0;
}

