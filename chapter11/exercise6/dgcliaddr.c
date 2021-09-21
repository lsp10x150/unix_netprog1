#include	"unp.h"
#include <netdb.h>

void
dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
	int				n;
	char			sendline[MAXLINE], recvline[MAXLINE + 1], straddr[INET_ADDRSTRLEN] = {0};
	socklen_t		len;
	struct sockaddr	*preply_addr;

	preply_addr = Malloc(servlen);

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

		len = servlen;
		n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
		struct hostent* h = gethostbyaddr(preply_addr, servlen, AF_INET);
		for (char** cur = h->h_addr_list; cur != NULL; cur++) {
			struct in_addr* ina = (struct in_addr*)cur;
			if ( inet_ntop(AF_INET, ina, straddr, INET_ADDRSTRLEN) != NULL) {
				struct hostent* g = gethostbyname(straddr);
				
			}
			
		}		
		if (len != servlen || memcmp(pservaddr, preply_addr, len) != 0) {
			printf("reply from %s (ignored)\n",
					Sock_ntop(preply_addr, len));
			continue;
		}

		recvline[n] = 0;	/* null terminate */
		Fputs(recvline, stdout);
	}
}
