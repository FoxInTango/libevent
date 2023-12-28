#include "EventReactor.h"
using namespace foxintango;
#include <map>
#include <atomic>

// TODO : LOAD FROM MODEL
unsigned int max_event_count  = 1024;
unsigned int max_accept_count = 1024;
int platform_io_process(EventReactor* reactor, EventTarget* target);

#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
//IOCP
#elif defined(__linux__) || defined(ANDROID) || defined(_ANDROID_)
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/sendfile.h>

// 将文件描述符设置成非阻塞
int setnonblocking(int handle) {
    int old_option = fcntl(handle, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(handle, F_SETFL, new_option);
    return old_option;
}
typedef struct _event_reactor_model_s {
    int epoll_handle;
    int event_handle_count;
    epoll_event  accept_event;
    epoll_event* epoll_events;
}event_reactor_model_s;
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
#else
#endif

std::map<EventReactor*, event_reactor_model_s> event_reactor_model_map;
std::atomic<bool> event_reactor_model_map_locked(false);
EventReactor::EventReactor() {
    // TODO 线程安全处理
    event_reactor_model_map.insert(std::pair< EventReactor*, event_reactor_model_s>(this, event_reactor_model_s()));
}

EventReactor::~EventReactor() {
    // TODO 线程安全处理
    if(event_reactor_model_map.count(this)){
        event_reactor_model_map.erase(this);
    }
}

int EventReactor::boot() {

}

#define __linux__

#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
#elif defined(__linux__) || defined(ANDROID) || defined(_ANDROID_)
int platform_io_process(EventReactor* reactor,EventTarget* target){
    bool platform_io_process_quit = false;
    while (event_reactor_model_map_locked.load())
    {
    }
    event_reactor_model_map_locked.store(true);

    if (event_reactor_model_map.count(reactor)) {
        event_reactor_model_s model = event_reactor_model_map.at(reactor);
        event_reactor_model_map_locked.store(false);// TODO 处理锁定时机 WAIT机制 std::condition_variable::wait std::atomic<T>::wait()
        model.epoll_handle = epoll_create1(0);
        if (model.epoll_handle > -1) {
            model.epoll_events = new epoll_event[max_event_count];
            model.accept_event.events = EPOLLIN;
            model.accept_event.data.fd = target->handle();
            if (epoll_ctl(model.epoll_handle, EPOLL_CTL_ADD, target->handle(), &model.accept_event) > -1) {
                while (false == platform_io_process_quit) {
                    model.event_handle_count = epoll_wait(model.epoll_handle, model.epoll_events, max_event_count, -1);

                    if (model.event_handle_count > -1) {
                        for (int i = 0; i < model.event_handle_count; ++i) {
                            if (model.epoll_events[i].data.fd == target->handle()) {
                                int accept_handle = 0;
                                socklen_t accept_count = max_accept_count;
                                struct sockaddr accept_address[max_accept_count];
                                accept_handle = accept(target->handle(), (struct sockaddr*)&accept_address, &accept_count);
                                if (accept_handle > -1) {
                                    setnonblocking(accept_handle);
                                    model.epoll_events[i].events = EPOLLIN | EPOLLET;
                                    model.epoll_events[i].data.fd = accept_handle;
                                    // TODO 处理加入队列失败
                                    if (epoll_ctl(model.epoll_handle, EPOLL_CTL_ADD, accept_handle, &model.epoll_events[i]) == -1) {

                                    }
                                }

                            }
                            else {
                                // TODO 数据处理
                                // do_use_fd(events[n].data.fd);
                            }
                        }
                    }// TO DO 失败处理 -- wait结果为-1的原因
                }
            }// TODO 失败处理
        }

    }
    return 0;
}
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
#else
#endif

