#include "stdafx.h"
#include "FileConfigParser.h"


FileConfigParser::FileConfigParser(const char* file_name)
{
    this->file_name = file_name;
}


FileConfigParser::~FileConfigParser(void)
{
}

void FileConfigParser::readData(void)   
{
    printf("FileConfigParser::readData\n");
}

void FileConfigParser::parseToken(void)
{
    printf("FileConfigParser::parseToken\n");
}

void FileConfigParser::buildModel(void)
{
    person_data.setName("i am file config parser");
    person_data.setHP(100);
    printf("FileConfigParser::buildModel\n");
}

void FileConfigParser::validate(void)
{
    printf("FileConfigParser::validate\n");
}

