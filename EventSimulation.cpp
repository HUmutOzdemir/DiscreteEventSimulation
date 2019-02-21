#include <iostream>
#include <fstream>
#include "Event.h"
#include "Person.h"
using namespace std;

class EventSimulation{
    vector<Person>* people;
    int luggageCountMax;
    int securityCountMax;
    int numberOfPerson;
public:
    EventSimulation(ifstream& infile){
        infile >> numberOfPerson;
        infile >> luggageCountMax;
        infile >> securityCountMax;
        people = new vector<Person>();
        for(int i=0;i<numberOfPerson;i++){
            int a,b,c,d;
            char e,f;
            infile >> a >> b >> c >> d;
            infile >> e >> f;
            Person* newPerson = new Person(a,b,c,d,e,f,i);
            people->push_back(*newPerson);
        }
    }
    void case1(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        queue<Person*>* luggageQueue = new queue<Person*>();
        queue<Person*>* securityQueue = new queue<Person*>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(luggageCount<luggageCountMax){
                    luggageCount++;
                    event.type=Event::LeaveLuggage;
                    event.time= event.time + event.person->lugWait;
                    eventQueue->push(event);
                }else{
                    luggageQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->front();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(securityCount<securityCountMax){
                    securityCount++;
                    event.type = Event::LeaveSecurity;
                    event.time = event.time + event.person->secWait;
                    eventQueue->push(event);
                }else{
                    securityQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->front();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }
    void case2(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        priority_queue<Person*,vector<Person*>,Person::FFFS>* luggageQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        priority_queue<Person*,vector<Person*>,Person::FFFS>* securityQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(luggageCount<luggageCountMax){
                    luggageCount++;
                    event.type=Event::LeaveLuggage;
                    event.time= event.time + event.person->lugWait;
                    eventQueue->push(event);
                }else{
                    luggageQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->top();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(securityCount<securityCountMax){
                    securityCount++;
                    event.type = Event::LeaveSecurity;
                    event.time = event.time + event.person->secWait;
                    eventQueue->push(event);
                }else{
                    securityQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->top();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }

    void case3(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        queue<Person*>* luggageQueue = new queue<Person*>();
        queue<Person*>* securityQueue = new queue<Person*>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(luggageCount<luggageCountMax){
                    luggageCount++;
                    event.type=Event::LeaveLuggage;
                    event.time= event.time + event.person->lugWait;
                    eventQueue->push(event);
                }else{
                    luggageQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->front();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(event.person->vip){
                    average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                    if(event.time>event.person->flightTime){
                        numOfLates++;
                    }
                    continue;
                }else {
                    if (securityCount < securityCountMax) {
                        securityCount++;
                        event.type = Event::LeaveSecurity;
                        event.time = event.time + event.person->secWait;
                        eventQueue->push(event);
                    } else {
                        securityQueue->push(event.person);
                    }
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->front();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }
    void case4(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        priority_queue<Person*,vector<Person*>,Person::FFFS>* luggageQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        priority_queue<Person*,vector<Person*>,Person::FFFS>* securityQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(luggageCount<luggageCountMax){
                    luggageCount++;
                    event.type=Event::LeaveLuggage;
                    event.time= event.time + event.person->lugWait;
                    eventQueue->push(event);
                }else{
                    luggageQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->top();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(event.person->vip){
                    average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                    if(event.time>event.person->flightTime){
                        numOfLates++;
                    }
                    continue;
                }else{
                    if(securityCount<securityCountMax){
                        securityCount++;
                        event.type = Event::LeaveSecurity;
                        event.time = event.time + event.person->secWait;
                        eventQueue->push(event);
                    }else{
                        securityQueue->push(event.person);
                    }
                    continue;
                }

            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->top();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }
    void case5(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        queue<Person*>* luggageQueue = new queue<Person*>();
        queue<Person*>* securityQueue = new queue<Person*>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(event.person->isThereLuggage){
                    if(luggageCount<luggageCountMax){
                        luggageCount++;
                        event.type=Event::LeaveLuggage;
                        event.time= event.time + event.person->lugWait;
                        eventQueue->push(event);
                    }else{
                        luggageQueue->push(event.person);
                    }
                    continue;
                }else{
                    if(securityCount<securityCountMax){
                        securityCount++;
                        event.type = Event::LeaveSecurity;
                        event.time = event.time + event.person->secWait;
                        eventQueue->push(event);
                    }else{
                        securityQueue->push(event.person);
                    }
                    continue;
                }
            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->front();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(securityCount<securityCountMax){
                    securityCount++;
                    event.type = Event::LeaveSecurity;
                    event.time = event.time + event.person->secWait;
                    eventQueue->push(event);
                }else{
                    securityQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->front();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }
    void case6(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        priority_queue<Person*,vector<Person*>,Person::FFFS>* luggageQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        priority_queue<Person*,vector<Person*>,Person::FFFS>* securityQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(event.person->isThereLuggage){
                    if(luggageCount<luggageCountMax){
                        luggageCount++;
                        event.type=Event::LeaveLuggage;
                        event.time= event.time + event.person->lugWait;
                        eventQueue->push(event);
                    }else{
                        luggageQueue->push(event.person);
                    }
                    continue;
                }else{
                    if(securityCount<securityCountMax){
                        securityCount++;
                        event.type = Event::LeaveSecurity;
                        event.time = event.time + event.person->secWait;
                        eventQueue->push(event);
                    }else{
                        securityQueue->push(event.person);
                    }
                    continue;
                }
            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->top();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(securityCount<securityCountMax){
                    securityCount++;
                    event.type = Event::LeaveSecurity;
                    event.time = event.time + event.person->secWait;
                    eventQueue->push(event);
                }else{
                    securityQueue->push(event.person);
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->top();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }
    void case7(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        queue<Person*>* luggageQueue = new queue<Person*>();
        queue<Person*>* securityQueue = new queue<Person*>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(event.person->isThereLuggage){
                    if(luggageCount<luggageCountMax){
                        luggageCount++;
                        event.type=Event::LeaveLuggage;
                        event.time= event.time + event.person->lugWait;
                        eventQueue->push(event);
                    }else{
                        luggageQueue->push(event.person);
                    }
                    continue;
                }else{
                    if(event.person->vip){
                        average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                        if(event.time>event.person->flightTime){
                            numOfLates++;
                        }
                        continue;
                    }else{
                        if (securityCount < securityCountMax) {
                            securityCount++;
                            event.type = Event::LeaveSecurity;
                            event.time = event.time + event.person->secWait;
                            eventQueue->push(event);
                        } else {
                            securityQueue->push(event.person);
                        }
                        continue;
                    }
                }

            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->front();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(event.person->vip){
                    average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                    if(event.time>event.person->flightTime){
                        numOfLates++;
                    }
                    continue;
                }else {
                    if (securityCount < securityCountMax) {
                        securityCount++;
                        event.type = Event::LeaveSecurity;
                        event.time = event.time + event.person->secWait;
                        eventQueue->push(event);
                    } else {
                        securityQueue->push(event.person);
                    }
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->front();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }
    void case8(ofstream& outFile){
        priority_queue<Event,vector<Event>,Event::Greater>* eventQueue = new priority_queue<Event,vector<Event>,Event::Greater>();
        vector<Person> :: iterator itr;
        for(itr = people->begin();itr!=people->end();++itr){
            Event* newEvent = new Event(Event::Arrival,itr->arriveTime,&*itr);
            eventQueue->push(*newEvent);
        }
        priority_queue<Person*,vector<Person*>,Person::FFFS>* luggageQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        priority_queue<Person*,vector<Person*>,Person::FFFS>* securityQueue = new priority_queue<Person*,vector<Person*>,Person::FFFS>();
        int securityCount=0,luggageCount=0;
        int numOfLates=0;
        double average=0;
        while(!eventQueue->empty()){
            Event event = eventQueue->top();
            eventQueue->pop();
            if(event.type==Event::Arrival){
                if(event.person->isThereLuggage){
                    if(luggageCount<luggageCountMax){
                        luggageCount++;
                        event.type=Event::LeaveLuggage;
                        event.time= event.time + event.person->lugWait;
                        eventQueue->push(event);
                    }else{
                        luggageQueue->push(event.person);
                    }
                    continue;
                }else{
                    if(event.person->vip){
                        average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                        if(event.time>event.person->flightTime){
                            numOfLates++;
                        }
                        continue;
                    }else{
                        if (securityCount < securityCountMax) {
                            securityCount++;
                            event.type = Event::LeaveSecurity;
                            event.time = event.time + event.person->secWait;
                            eventQueue->push(event);
                        } else {
                            securityQueue->push(event.person);
                        }
                        continue;
                    }
                }

            }
            if(event.type==Event::LeaveLuggage){
                luggageCount--;
                if(!luggageQueue->empty()){
                    luggageCount++;
                    Person* p = luggageQueue->top();
                    luggageQueue->pop();
                    Event* newEvent = new Event(Event::LeaveLuggage,event.time+p->lugWait,p);
                    eventQueue->push(*newEvent);
                }
                if(event.person->vip){
                    average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                    if(event.time>event.person->flightTime){
                        numOfLates++;
                    }
                    continue;
                }else {
                    if (securityCount < securityCountMax) {
                        securityCount++;
                        event.type = Event::LeaveSecurity;
                        event.time = event.time + event.person->secWait;
                        eventQueue->push(event);
                    } else {
                        securityQueue->push(event.person);
                    }
                }
                continue;
            }
            if(event.type==Event::LeaveSecurity){
                securityCount--;
                if(!securityQueue->empty()){
                    securityCount++;
                    Person* p = securityQueue->top();
                    securityQueue->pop();
                    Event* newEvent = new Event(Event::LeaveSecurity,event.time+p->secWait,p);
                    eventQueue->push(*newEvent);
                }
                average += (double)(event.time-event.person->arriveTime)/numberOfPerson;
                if(event.time>event.person->flightTime){
                    numOfLates++;
                }
                continue;
            }
        }
        outFile << average << " " << numOfLates << endl;
    }

};
