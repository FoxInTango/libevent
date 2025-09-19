#ifndef _EVENT_SESSION_H_
#define _EVENT_SESSION_H_

#include <libprotocol/libprotocol.h>
#include <libcpp/libcpp.h>

EXTERN_C_BEGIN
namespaceBegin(foxintango)

class foxintangoAPI EventSession :public ProtocolContext {
public:
    EventSession();
    virtual ~EventSession();
public:
};
namespaceEnd
EXTERN_C_END
#endif // !_EVENT_SESSION_H_
