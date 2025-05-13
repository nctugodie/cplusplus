#pragma once
#include "configparser.h"
class DBConfigParser :
    public ConfigParser
{
public:
    DBConfigParser(const char* connection_string);
    virtual ~DBConfigParser(void);

protected:
    virtual void readData(void);
    virtual void parseToken(void);
    virtual void buildModel(void);
    virtual void validate(void);

private:
    std::string connection_string;
};

