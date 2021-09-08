#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	int udp_sock, tcp_sock, sctp_sock;
	socklen_t optlen = sizeof(int);
	udp_sock = socket(AF_INET, SOCK_DGRAM, NULL);
	tcp_sock = socket(AF_INET, SOCK_STREAM, NULL);
	sctp_sock = socket(AF_INET, SOCK_SEQPACKET, NULL);	
	int sendbufsize, rcvbufsize;
	int n = getsockopt(udp_sock, SOL_SOCKET, SO_SNDBUF, &sendbufsize, &optlen);
	n = getsockopt(udp_sock, SOL_SOCKET, SO_RCVBUF, &rcvbufsize, &optlen);
	printf("UDP: sendbuf size = %d recvbuf size = %d;\n", sendbufsize, rcvbufsize); 
	
	n = getsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, &sendbufsize, &optlen);
	n = getsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, &rcvbufsize, &optlen);
	printf("TCP: sendbuf size = %d recvbuf size = %d;\n", sendbufsize, rcvbufsize);
	
	n = getsockopt(sctp_sock, SOL_SOCKET, SO_SNDBUF, &sendbufsize, &optlen);
	n = getsockopt(sctp_sock, SOL_SOCKET, SO_RCVBUF, &rcvbufsize, &optlen);
	printf("SCTP: sendbuf size = %d recvbuf size = %d;\n", sendbufsize, rcvbufsize);
}
