#pragma once
#include "iagentstate.h"

class DeadState : public IAgentState
{
public:
    DeadState(void);
    virtual ~DeadState(void);

    virtual void hit(Agent* agent);
    virtual void heal(Agent* agent);
    virtual void fight(Agent* agent);
    virtual void search(Agent* agent);
};

