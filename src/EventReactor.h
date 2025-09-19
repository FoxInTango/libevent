#ifndef _LIBEVENT_REACTOR_H_
#define _LIBEVENT_REACTOR_H_

#include "EventEndpoint.h"
#include <libplatform/libplatform.h>
#include <libcpp/libcpp.h>
#include <set>

EXTERN_C_BEGIN
namespaceBegin(foxintango)

class foxintangoAPI EventReactorProcessHandler{
public:
enum Phase{
    
};
enum Action{
    WAIT
};
public:
    EventReactorProcessHandler();
    virtual ~EventReactorProcessHandler();
public:
    virtual Action handleEventloop(Phase phase);
};
typedef struct _EventReactorCreateInfo{
    size_t BufferSize;
    size_t EventCount;
    size_t ThreadCount;
    _EventReactorCreateInfo():BufferSize(0),EventCount(0),ThreadCount(0){}
}EventReactorCreateInfo;
class foxintangoAPI EventReactor :public PlatformEventReactorContext{ 
private:
    std::set<EventEndpoint*> endpoints;
    EventReactorProcessHandler* processHandler;
public:
    EventReactor();
    EventReactor(const EventReactorCreateInfo& info);
   ~EventReactor();
public:
   void attach();
   void detach();
public:
   int acceptEndpoint(EventEndpoint* endpoint);
   int remvoeEndpoint(EventEndpoint* endpoint);
};
namespaceEnd
EXTERN_C_END
#endif
