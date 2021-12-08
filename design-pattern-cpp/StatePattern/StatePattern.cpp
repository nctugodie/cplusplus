// StatePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Agent.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
    Agent agent;

    assert(Agent::s_HealthState == agent.getCurrentState());
    agent.heal(80);
    assert(Agent::MAX_HP == agent.getHP());
    assert(Agent::s_HealthState == agent.getCurrentState());

    agent.hit(30);
    assert(Agent::s_HealthState == agent.getCurrentState());
    agent.hit(1);
    assert(Agent::s_InjuredState == agent.getCurrentState());

    agent.heal(31);
    assert(Agent::MAX_HP == agent.getHP());
    assert(Agent::s_HealthState == agent.getCurrentState());

    agent.hit(Agent::MAX_HP);
    assert(Agent::MIN_HP == agent.getHP());
    assert(Agent::s_DeadState == agent.getCurrentState());

	return 0;
}

