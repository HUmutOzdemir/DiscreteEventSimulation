#ifndef PROJECT2_PERSON_H
#define PROJECT2_PERSON_H

#include <iostream>
using namespace std;

class Person {
public:
    int arriveTime;
    int flightTime;
    int lugWait;
    int secWait;
    bool vip;
    bool isThereLuggage;
    int id;

    struct FFFS{
        bool operator()(const Person* lhs, const Person* rhs) const {
            if(lhs->flightTime == rhs->flightTime){
                return lhs->arriveTime > rhs->arriveTime;
            }
            return lhs->flightTime>rhs->flightTime;
        }
    };
    Person(int arriveTime ,int flightTime, int lugWait, int secWait, char vip, char isThereLuggage,int id);
    bool operator<(const Person& person);
    bool operator>(const Person& person);
    bool operator==(const Person& person);
    ~Person();
};
#endif //PROJECT2_PERSON_H
