#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

#pragma once
#include <iostream>
#include <list>

template<typename TYPE, typename TokenType>
class WorkObserver
{
public:
    virtual TokenType notifyWork(TYPE obj) = 0;
    virtual void notifyEmpty(TokenType listIt) = 0;
};

template<typename TYPE>
class ActiveWorkers : public WorkObserver<TYPE, typename std::list<TYPE>::iterator>
{
private:
    typename std::list<TYPE> _list;

public:
    typedef typename std::list<TYPE>::iterator TokenType;

    TokenType notifyWork(TYPE obj) override final {
        _list.push_front(obj);
        if (obj->subject != nullptr)
            obj->subject->schedule_sub();
        return _list.begin();
    }

    void notifyEmpty(TokenType listIt) override final {
        _list.erase(listIt);
    }

    bool isEmpty() {
        return _list.empty();
    }

    void print() {
        for (auto listIt = _list.begin(); listIt != _list.end();) {
            auto curIter = listIt++;
            (*curIter)->print();
        }
    }
};



#endif // OBSERVER_H_INCLUDED

