#ifndef _LIBEVENT_ENDPOINT_H_
#define _LIBEVENT_ENDPOINT_H_

#include <libplatform/libplatform.h>
#include <libcpp/libcpp.h>
namespaceBegin(foxintango)
EXTERN_C_BEGIN

class EventReactor;

typedef struct _EventEndpointCreateInfo{
char* location;
int   port;
int   protocol;
}EventEndpointCreateInfo;

class foxintangoAPI EventEndpoint :public PlatformEventEndpointContext{
public:
    EventEndpoint();
    virtual ~EventEndpoint();
public:
    //virtual EventStatus handleEvent();
};
EXTERN_C_END
namespaceEnd
#endif
