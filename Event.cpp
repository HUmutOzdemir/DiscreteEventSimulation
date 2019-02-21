#include "Event.h"

Event::Event(EventType type, int startTime,Person* person) {
    this->type = type;
    this->time = startTime;
    this->person = person;
}
bool Event::operator<(const Event& event){
    if(this->time<event.time){
        return true;
    }else if(this->time==event.time){
        if(this->type<event.type){
            return true;
        }else if(event.type==this->type){
            return *(this->person)<*(event.person);
        }
    }
    return false;
}
bool Event::operator>(const Event& event){
    if(this->time>event.time){
        return true;
    }else if(this->time==event.time){
        if(this->type>event.type){
            return true;
        }else if(event.type==this->type){
            return *(this->person)>*(event.person);
        }
    }
    return false;
}
Event ::~Event() {

}

