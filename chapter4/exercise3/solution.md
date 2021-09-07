# Exercise 4.3
On child's close reference counter will be decremented by one, but the connection will be terminated, because parent still holds the reference to the socket. On server's close socket's reference counter will be equal to zero and connection will closed. 
