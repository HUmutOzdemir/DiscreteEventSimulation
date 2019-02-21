#ifndef PROJECT2_EVENT_H
#define PROJECT2_EVENT_H

#include "Person.h"
#include <iostream>
#include <queue>

using namespace std;

class Event {
public:
    enum EventType {Arrival=2,LeaveLuggage=1,LeaveSecurity=0};
    EventType type;
    int time;
    Person* person;

    struct Greater{
        bool operator()(const Event& lhs, const Event& rhs) const
        {
            if(lhs.time>rhs.time){
                return true;
            }else if(lhs.time==rhs.time){
                if(lhs.type>rhs.type){
                    return true;
                }else if(rhs.type==lhs.type){
                    return *(lhs.person)>*(rhs.person);
                }
            }
            return false;
        }
    };


    Event(EventType type,int startTime,Person* person);
    bool operator<(const Event& e1);
    bool operator>(const Event& e1);
    ~Event();

};

#endif //PROJECT2_EVENT_H
