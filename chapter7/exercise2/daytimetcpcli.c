#include	"unp.h"
#include <sys/socket.h>
#include <netinet/tcp.h>
void print_opts(int sockfd) {
	int rcvbufsize = 0, mss = 0, res = 0;
	socklen_t optlen = sizeof(int);
	res = getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &rcvbufsize, &optlen);	
	res = getsockopt(sockfd, IPPROTO_TCP, TCP_MAXSEG, &mss, &optlen);
	printf("rcvbuf size = %d, mss = %d\n", rcvbufsize, mss);
}

int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", argv[1]);

	print_opts(sockfd);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");

	printf("\nafter connect:\n");
	print_opts(sockfd);	

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	exit(0);
}
