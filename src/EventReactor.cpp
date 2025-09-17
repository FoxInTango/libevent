#include "EventReactor.h"
#include "EventEndpoint.h"
using namespace foxintango;
#include <assert.h>
EventReactor::EventReactor(const EventReactorCreateInfo& info) {
    bufferSize  = info.BufferSize;
    eventCount  = info.EventCount;
    threadCount = info.ThreadCount;
    prepare();
    for(size_t i = 0;i < threadCount;i ++) {
        //std::thread t(event_reactor_process,this);
	//t.detach();
    }
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
