#pragma once

#include <string>

class PersonData
{
public:
    PersonData()
    {
        name = "";
        hp = 0;
    }

    ~PersonData()
    {
    }

    std::string getName()
    {
        return name;
    }

    int getHP()
    {
        return hp;
    }

    void setName(const char* new_name)
    {
        name = new_name;
    }

    void setHP(int new_hp)
    {
        hp = new_hp;
    }

private:
    std::string name;
    int hp;
};

class ConfigParser
{
public:
    ConfigParser(void);
    virtual ~ConfigParser(void);
    PersonData doParse(void);
protected:
    virtual void readData(void) = 0;
    virtual void parseToken(void) = 0;
    virtual void buildModel(void) = 0;
    virtual void validate(void) = 0;

protected:
    PersonData person_data;
};

