#include "stdafx.h"
#include "HealthState.h"

HealthState::HealthState(void)
{
}


HealthState::~HealthState(void)
{
}

void HealthState::hit(Agent* agent)
{
    if (agent->getHP() < Agent::INJURED_LOW_LIMIT)
        agent->chageState(Agent::s_DeadState);
    else if (agent->getHP() < Agent::HEALTH_LOW_LIMIT)
        agent->chageState(Agent::s_InjuredState);

    printf("HealthState::hit\n");
}

void HealthState::heal(Agent* agent)
{
    printf("HealthState::heal\n");
}

void HealthState::fight(Agent* agent)
{
    printf("HealthState::fight\n");
}

void HealthState::search(Agent* agent)
{
    printf("HealthState::search\n");
}
