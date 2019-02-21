#include "Person.h"
#include <iostream>

Person :: Person(int arriveTime ,int flightTime, int lugWait, int secWait, char vip, char isThereLuggage,int id){
        this->arriveTime = arriveTime;
        this->flightTime = flightTime;
        this->lugWait = lugWait;
        this->secWait = secWait;
        this->id = id;
        if(vip=='V'){
            this->vip = true;
        }else{
            this->vip = false;
        }
        if(isThereLuggage=='L'){
            this->isThereLuggage = true;
        }else{
            this->isThereLuggage = false;
        }
}
bool Person::operator==(const Person& person){
    return this->id == person.id;
}
bool Person::operator<(const Person& person){
    return this->arriveTime<person.arriveTime;
}
bool Person::operator>(const Person& person) {
    return this->arriveTime>person.arriveTime;
}
Person::~Person(){};