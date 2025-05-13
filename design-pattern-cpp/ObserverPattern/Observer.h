#pragma once

#include <vector>

class IObserver;

class ISubject
{
public:
    virtual void addObserver(IObserver* observer) = 0;
    virtual void deleteObserver(IObserver* observer) = 0;
    virtual void notifyObserver() = 0;
};

class IObserver
{
public:
    virtual void update(ISubject* subject) = 0;
};

class MonitoredItem : public ISubject
{
public:
    enum
    {
        OK = 1,
        CRITICAL = 2
    };

public:
    MonitoredItem()
    {
        _status = MonitoredItem::OK;
    }

    ~MonitoredItem()
    {
    }

    virtual void addObserver(IObserver* observer)
    {
        _observers.push_back(observer);
    }

    virtual void deleteObserver(IObserver* observer)
    {
    }

    virtual void notifyObserver()
    {
        for (auto iter : _observers)
        {
            iter->update(this);
        }
    }

    int getStatus()
    {
        return _status;
    }

    void changeStatus(int status)
    {
        _status = status;
        notifyObserver();
    }

private:
    std::vector<IObserver*> _observers;
    int _status;
};

class ChangeLoger : public IObserver
{
public:
    ChangeLoger()
    {
    }

    ~ChangeLoger()
    {
    }

    virtual void update(ISubject* subject)
    {
        writeChangeLog(dynamic_cast<MonitoredItem*>(subject)->getStatus());
    }

private:
    void writeChangeLog(int status)
    {
        printf("ChangeLogger writeChangeLog status = %d\n", status);
    }
};

class MockChangeLogger : public IObserver
{
public:
    MockChangeLogger()
    {
        _notifiedCount = 0;
    }

    ~MockChangeLogger()
    {
    }

    virtual void update(ISubject* subject)
    {
        _notifiedCount++;
    }

public:
    int _notifiedCount;
};

