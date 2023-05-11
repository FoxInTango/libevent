#ifndef _EVENT_TARGET_H_
#define _EVENT_TARGET_H_
#include <libcpp/libcpp.h>

namespaceBegin(foxintango)
/*
class foxintangoAPI EventTargetAction{
public:
    EventTargetAction()
    virtual ~EventTargetAction();
};
*/
class foxintangoAPI EventTarget {
public:
    EventTarget();
    virtual ~EventTarget();
public:
    virtual int handle() = 0;
};
namespaceEnd
#endif // !_EVENT_TARGET_H_