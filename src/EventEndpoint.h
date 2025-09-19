#ifndef _LIBEVENT_ENDPOINT_H_
#define _LIBEVENT_ENDPOINT_H_
#include "EventSession.h"
#include <libprotocol/libprotocol.h>
#include <libplatform/libplatform.h>
#include <libcpp/libcpp.h>
#include <string>
#include <map>
EXTERN_C_BEGIN
namespaceBegin(foxintango)
class EventReactor;
typedef struct _EventEndpointCreateInfo{
char* url;
int   port;
int   protocol;
}EventEndpointCreateInfo;

class foxintangoAPI EventEndpoint :public PlatformEventEndpointContext{
protected:
    std::map<std::string,EventSession*> sessionMap; 
public:
    EventEndpoint();
    virtual ~EventEndpoint();
public:
    int attach(EventReactor* reactor);
    int detach();
};
namespaceEnd
EXTERN_C_END
#endif
