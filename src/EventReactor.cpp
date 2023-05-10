#include "EventReactor.h"
using namespace foxintango;

EventReactor::EventReactor() {
}

EventReactor::~EventReactor() {
}

int EventReactor::boot() {

}

#define _DEVELOP_

#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
#elif defined(__linux__) || defined(ANDROID) || defined(_ANDROID_) || defined(_DEVELOP_)
#include <sys/epoll.h>

#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
#else
#endif

