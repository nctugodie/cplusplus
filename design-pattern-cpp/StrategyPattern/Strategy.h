#pragma once

#include "stdafx.h"

class IBatStrategy
{
public:
    virtual void swing() = 0;
};

class FreeBatStrategy : public IBatStrategy
{
public:
    FreeBatStrategy()
    {
    }

    ~FreeBatStrategy()
    {
    }

    virtual void swing()
    {
        printf("FreeBatStrategy swing\n");
    }
};

class HomeRunStrategy : public IBatStrategy
{
public:
    HomeRunStrategy()
    {
    }

    ~HomeRunStrategy()
    {
    }

    virtual void swing()
    {
        printf("HomeRunStrategy swing\n");
    }
};

class BuntStrategy : public IBatStrategy
{
public:
    BuntStrategy()
    {
    }

    ~BuntStrategy()
    {
    }

    virtual void swing()
    {
        printf("BuntStrategy swing\n");
    }
};

class SacrificeFlyStrategy : public IBatStrategy
{
public:
    SacrificeFlyStrategy()
    {
    }

    ~SacrificeFlyStrategy()
    {
    }

    virtual void swing()
    {
        printf("SacrificeFlyStrategy swing\n");
    }
};

class Player
{
public:
    Player(IBatStrategy* strategy)
    {
        _strategy = strategy;
    }

    ~Player()
    {
    }

    void bat()
    {
        _strategy->swing();
    }

private:
    IBatStrategy* _strategy;
};

