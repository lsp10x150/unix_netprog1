# Exercise 8.1
We have two applications, one using TCP and the other using UDP. 4'096 bytes are in the receive buffer for the TCP socket and two 2'048-byte datagrams are in the receive buffer for the UDP socket. The TCP application calls read with a third argument of 4'096 and the UDP application calls recvfrom with a third argument of 4'096. Is there any difference?
