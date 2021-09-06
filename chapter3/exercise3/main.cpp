#include <arpa/inet.h>
#include <cerrno>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>

int my_pton(int af, const char* src, void* dst) {
    int n = 0;
	if (af == AF_INET) {
		n = inet_pton(af, src, dst);
		if (n == 0) {
			struct in_addr addr{};
			n = inet_aton(src, &addr);
			if (n == 0) return 0;
			else {
				memcpy(dst, &addr, 4);
				return 1;
			}
		} else {
			return n;
		}	
	} else if (af == AF_INET6) {
		n = inet_pton(af, src, dst);
		if (n == 0) {
			struct in_addr addr{};
			n = inet_aton(src, &addr);
			if (n == 0) return 0;	
			else { 
				for (int i = 0; i < 16; i++) *((char*)dst+i) = 0;
				memcpy((char*)dst + 12, &addr, 4);
				return 1;	
			}
		} else {
			return n;
		}		
	}
	errno = EAFNOSUPPORT;
	return -1;
}

int main() {
	struct in6_addr addr{};
	int n = my_pton(AF_INET6, "ffff:ffff:ffff:ffff:ffff:ffff:f22f:ff2f", &addr);
	if (n == 0) return EXIT_FAILURE;
	else return (int)*((char*)&addr+12);
}

