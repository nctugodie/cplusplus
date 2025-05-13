#pragma once

#include "stdafx.h"
#include <exception>
#include <vector>

class IWeapon
{
public:
    virtual bool add(IWeapon* weapon) = 0;
    virtual bool remove(IWeapon* weapon) = 0;
    virtual IWeapon* getChild(int index) = 0;
    virtual void fire() = 0;
};

class LineBullet : public IWeapon
{
public:
    LineBullet()
    {
    }

    ~LineBullet()
    {
    }

    virtual bool add(IWeapon* weapon)
    {
        throw std::exception();
    }

    virtual bool remove(IWeapon* weapon)
    {
        throw std::exception();
    }

    virtual IWeapon* getChild(int index)
    {
        throw std::exception();
    }

    virtual void fire()
    {
        printf("LinBullet fire\n");
    }
};

class TraceBullet : public IWeapon
{
public:
    TraceBullet()
    {
    }

    ~TraceBullet()
    {
    }

    virtual bool add(IWeapon* weapon)
    {
        throw std::exception();
    }

    virtual bool remove(IWeapon* weapon)
    {
        throw std::exception();
    }

    virtual IWeapon* getChild(int index)
    {
        throw std::exception();
    }

    virtual void fire()
    {
        printf("TraceBullet fire\n");
    }
};

class Clip : public IWeapon
{
public:
    Clip()
    {
    }

    ~Clip()
    {
    }

    virtual bool add(IWeapon* weapon)
    {
        _list.push_back(weapon);
        return true;
    }

    virtual bool remove(IWeapon* weapon)
    {
        return false;
    }

    virtual IWeapon* getChild(int index)
    {
        return NULL;
    }

    virtual void fire()
    {
        for (auto iter : _list)
        {
            iter->fire();
        }
    }

private:
    std::vector<IWeapon*> _list;
};

