#include <sys/socket.h>
#include <netdb.h>

int getnameinfo_timeo(const struct sockaddr* addr, socklen_t addrlen,
			char* host, socklen_t hostlen,
			char* serv, socklen_t servlent, int flags,
			int timeo_sec);
