#include "getnameinfo_timeo.h"
#include <signal.h>
#include <unistd.h>

static void 
mere_interrupt(int signo) {
	return;
}

int getnameinfo_timeo(const struct sockaddr* addr, socklen_t addrlen, 
			char* host, socklen_t hostlen,
			char* serv, socklen_t servlen, int flags, 
			int timeo_sec) {
	void (*old_one)(int) = signal(SIGALRM, mere_interrupt);
	static char addrs[128] = {0};
	if (alarm(timeo_sec) != 0) 
		perror("connect_timeo: alarm was already set");
	int r = -2; 
	r = getnameinfo(addr, addrlen, host, hostlen, serv, servlen, flags);
	alarm(0);
	signal(SIGALRM, old_one);	
	
	if (r == -2) {
		if ( inet_ntop(AF_INET, ((struct sockaddr_in*)addr)->sin_addr, addr, 128) != NULL)
		return addrs;
	}
	if (r == 0) {
		return NULL;
	}
}
