#pragma once
#include "iagentstate.h"

class HealthState : public IAgentState
{
public:
    HealthState(void);
    virtual ~HealthState(void);

    virtual void hit(Agent* agent);
    virtual void heal(Agent* agent);
    virtual void fight(Agent* agent);
    virtual void search(Agent* agent);
};

