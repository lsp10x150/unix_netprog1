#include	"unp.h"
#include <signal.h>

void pipe_handler(int signo) {
	printf("SIGPIPE\n");
	return;
}

int
main(int argc, char **argv)
{
	int			sockfd;
	struct sockaddr_in	servaddr;


	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	if ( signal(SIGPIPE, pipe_handler) == SIG_ERR) 
		perror("setting up signal");
	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	sleep(2);
	Writen(sockfd, "some bytes\n", 11);
	sleep(10);
	Writen(sockfd, "another bytes\n", 14);
	exit(0);
}
