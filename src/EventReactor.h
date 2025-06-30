#ifndef _EVENT_REACTOR_H_
#define _EVENT_REACTOR_H_
#include "EventTarget.h"
#include <libcpp/libcpp.h>

namespaceBegin(foxintango)

class EventReactor{
public:
    EventReactor();
    virtual ~EventReactor();
public:
    virtual int boot();
public:
    int watch(int fd,const EventHandler* handler);
    int unwatch(int fd);
public:
    int setHandler(EventHandler* handler,int target);
    int removeHandler(EventHandler* handler);
};
namespaceEnd
#endif // !_EVENT_REACTOR_H_
