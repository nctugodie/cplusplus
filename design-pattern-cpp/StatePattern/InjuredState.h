#pragma once
#include "iagentstate.h"

class InjuredState : public IAgentState
{
public:
    InjuredState(void);
    virtual ~InjuredState(void);

    virtual void hit(Agent* agent);
    virtual void heal(Agent* agent);
    virtual void fight(Agent* agent);
    virtual void search(Agent* agent);
};

