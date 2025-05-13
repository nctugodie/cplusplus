#include "stdafx.h"
#include "ConfigParser.h"


ConfigParser::ConfigParser(void)
{
}


ConfigParser::~ConfigParser(void)
{
}


PersonData ConfigParser::doParse(void)
{
    readData();
    parseToken();
    buildModel();
    validate();

    return person_data;
}

