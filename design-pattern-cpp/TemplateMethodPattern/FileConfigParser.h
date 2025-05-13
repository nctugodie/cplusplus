#pragma once
#include "configparser.h"
class FileConfigParser :
    public ConfigParser
{
public:
    FileConfigParser(const char* file_name);
    virtual ~FileConfigParser(void);

protected:
    virtual void readData(void);
    virtual void parseToken(void);
    virtual void buildModel(void);
    virtual void validate(void);

private:
    std::string file_name;
};

