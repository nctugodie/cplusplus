// ObserverPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Observer.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
    MonitoredItem mi;
    MockChangeLogger* logger = new MockChangeLogger();
    mi.addObserver(logger);

    assert(0 == logger->_notifiedCount);
    mi.changeStatus(MonitoredItem::CRITICAL);
    assert(1 == logger->_notifiedCount);

    mi.changeStatus(MonitoredItem::CRITICAL);
    assert(2 == logger->_notifiedCount);

    delete logger;

	return 0;
}

