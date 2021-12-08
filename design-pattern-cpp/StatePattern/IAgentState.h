#pragma once

#include "Agent.h"

class IAgentState
{
public:
    IAgentState(void);
    virtual ~IAgentState(void);

    virtual void hit(Agent* agent) = 0;
    virtual void heal(Agent* agent) = 0;
    virtual void fight(Agent* agent) = 0;
    virtual void search(Agent* agent) = 0;
};

