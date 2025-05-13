#include "stdafx.h"
#include "Agent.h"
#include "IAgentState.h"
#include "HealthState.h"
#include "InjuredState.h"
#include "DeadState.h"

IAgentState* Agent::s_HealthState   = new HealthState;
IAgentState* Agent::s_InjuredState  = new InjuredState;
IAgentState* Agent::s_DeadState     = new DeadState;

Agent::Agent(void)
{
    _currentState   = s_HealthState;
    _HP             = Agent::MAX_HP;
}

Agent::~Agent(void)
{
    _currentState   = NULL;
    _HP             = Agent::MIN_HP;
}

int Agent::getHP()
{
    return _HP;
}

void Agent::hit(int point)
{
    _HP = _HP - point;
    if (_HP < Agent::MIN_HP)
        _HP = Agent::MIN_HP;

    _currentState->hit(this);
}

void Agent::heal(int point)
{
    _HP = _HP + point;
    if (_HP > Agent::MAX_HP)
        _HP = Agent::MAX_HP;

    _currentState->heal(this);
}

void Agent::fight()
{
    _currentState->fight(this);
}

void Agent::search()
{
    _currentState->search(this);
}

void Agent::chageState(IAgentState* state)
{
    _currentState = state;
}

IAgentState* Agent::getCurrentState()
{
    return _currentState;
}
