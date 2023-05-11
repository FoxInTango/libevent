#include "Event.h"
using namespace foxintango;
#include <typeinfo>
#include <string>

Event::Event(){
}

Event::~Event() {
}

unsigned int Event::type(){
    return 0;
    char* type = *(this->entity->subelementAt("type"));
    //return (unsigned int)((typeid(this)).hash_code);
}