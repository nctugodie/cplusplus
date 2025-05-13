#include "stdafx.h"
#include "InjuredState.h"


InjuredState::InjuredState(void)
{
}


InjuredState::~InjuredState(void)
{
}

void InjuredState::hit(Agent* agent)
{
    if (agent->getHP() < Agent::INJURED_LOW_LIMIT)
        agent->chageState(Agent::s_DeadState);

    printf("InjuredState::hit\n");
}

void InjuredState::heal(Agent* agent)
{
    if (agent->getHP() >= Agent::HEALTH_LOW_LIMIT)
        agent->chageState(Agent::s_HealthState);

    printf("InjuredState::heal\n");
}

void InjuredState::fight(Agent* agent)
{
    printf("InjuredState::fight\n");
}

void InjuredState::search(Agent* agent)
{
    printf("InjuredState::search\n");
}

