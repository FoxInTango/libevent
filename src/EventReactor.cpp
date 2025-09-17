#include "EventReactor.h"
#include "EventEndpoint.h"
using namespace foxintango;
#include <thread>
#include <assert.h>
EventReactor::EventReactor(const EventReactorCreateInfo& info) {
    bufferSize  = info.BufferSize;
    eventCount  = info.EventCount;
    threadCount = info.ThreadCount;
    prepare();
}
EventReactor::~EventReactor() {}
int EventReactor::acceptEndpoint(EventEndpoint* e){
    assert(e);

    e->reactor = this;

    // PlatformEventContext::add
    return 0;
}
int EventReactor::remvoeEndpoint(EventEndpoint* e){
    assert(e);

    return 0;
}
