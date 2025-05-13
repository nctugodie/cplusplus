// TemplateMethodPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileConfigParser.h"
#include "DBConfigParser.h"
#include <assert.h>
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
    PersonData person_data;

    FileConfigParser fileConfig("c:\\test.cfg");
    person_data = fileConfig.doParse();
    assert(0 == person_data.getName().compare("i am file config parser"));
    assert(100 == person_data.getHP());

    DBConfigParser dbConfig("http://127.0.0.1/myDB");
    person_data = dbConfig.doParse();
    assert(0 == person_data.getName().compare("i am db config parser"));
    assert(50 == person_data.getHP());

	return 0;
}

