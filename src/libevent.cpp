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

int libevent_listen(const int& fd, EventHandler* handler){
    return 0;
}

int libevent_discard(const int& fd){
    return 0;
}