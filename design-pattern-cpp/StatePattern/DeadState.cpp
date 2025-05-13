#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState(void)
{
}


DeadState::~DeadState(void)
{
}

void DeadState::hit(Agent* agent)
{
    printf("DeadState::hit\n");
}

void DeadState::heal(Agent* agent)
{
    if (agent->getHP() >= Agent::HEALTH_LOW_LIMIT)
        agent->chageState(Agent::s_HealthState);
    else if (agent->getHP() >= Agent::INJURED_LOW_LIMIT)
        agent->chageState(Agent::s_HealthState);

    printf("DeadState::heal\n");
}

void DeadState::fight(Agent* agent)
{
    printf("DeadState::fight\n");
}

void DeadState::search(Agent* agent)
{
    printf("DeadState::search\n");
}

