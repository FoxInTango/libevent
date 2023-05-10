#include "Event.h"
using namespace foxintango;
#include <typeinfo>

Event::Event(){
}

Event::~Event() {
}

unsigned int Event::type(){
    return 0;
    //return (unsigned int)((typeid(this)).hash_code);
}