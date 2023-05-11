#include "libevent.h"

int libevent_startup(const Model& model){
    return 0;
}

int libevent_reload(const Model& model){
    return 0;
}

int libevent_shutdown() {
    return 0;
}

int libevent_listen(EventTarget* target, EventHandler* handler){
    return 0;
}

int libevent_discard(EventTarget* target){
    return 0;
}