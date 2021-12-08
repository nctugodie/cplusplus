#pragma once

class IAgentState;

class Agent
{
public:
    enum
    {
        HEALTH_LOW_LIMIT    = 70,
        INJURED_LOW_LIMIT   = 1,
        HEAL_LOW_LIMIT      = 0
    };

    enum
    {
        MAX_HP = 100,
        MIN_HP = 0
    };

public:
    Agent(void);
    ~Agent(void);

    int getHP();
    void hit(int point);
    void heal(int point);
    void fight();
    void search();
    void chageState(IAgentState* state);
    IAgentState* getCurrentState();

public:
    static IAgentState* s_HealthState;
    static IAgentState* s_InjuredState;
    static IAgentState* s_DeadState;

private:
    IAgentState*    _currentState;
    int             _HP;
};

