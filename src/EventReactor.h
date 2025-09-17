#ifndef _LIBEVENT_REACTOR_H_
#define _LIBEVENT_REACTOR_H_


#include <libplatform/libplatform.h>
#include <libcpp/libcpp.h>
namespaceBegin(foxintango)
EXTERN_C_BEGIN

class EventEndpoint;

class foxintangoAPI EventReactorProcessHandler{
public:
public:
    EventReactorProcessHandler();
    virtual ~EventReactorProcessHandler();
public:
    //virtual int 
};
typedef struct _EventReactorCreateInfo{
    size_t BufferSize;
    size_t EventCount;
    size_t ThreadCount;
}EventReactorCreateInfo;
class foxintangoAPI EventReactor :public PlatformEventReactorContext{ 
public:
    EventReactor(const EventReactorCreateInfo& info);
   ~EventReactor();
public:
   void attach();
   void detach();
public:
   int acceptEndpoint(EventEndpoint* endpoint);
   int remvoeEndpoint(EventEndpoint* endpoint);
};
EXTERN_C_END
namespaceEnd
#endif
