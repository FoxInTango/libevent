#define ev_select 1
#define ev_poll   2
#define ev_epoll  3

int ev_init();
int ev_listen_fd(int fd);
int ev_free_fd(int fd);
int ev_stop();