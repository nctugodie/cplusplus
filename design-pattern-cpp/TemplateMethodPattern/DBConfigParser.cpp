#include "stdafx.h"
#include "DBConfigParser.h"


DBConfigParser::DBConfigParser(const char* connection_string)
{
    this->connection_string = connection_string;
}


DBConfigParser::~DBConfigParser(void)
{
}

void DBConfigParser::readData(void)   
{
    printf("DBConfigParser::readData\n");
}

void DBConfigParser::parseToken(void)
{
    printf("DBConfigParser::parseToken\n");
}

void DBConfigParser::buildModel(void)
{
    person_data.setName("i am db config parser");
    person_data.setHP(50);
    printf("DBConfigParser::buildModel\n");
}

void DBConfigParser::validate(void)
{
    printf("DBConfigParser::validate\n");
}

