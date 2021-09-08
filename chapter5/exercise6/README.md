# Exercise 5.6 
To verify what we claimed happens with SIGPIPE in Section 5.13, modify Figure 5.4 as follows:
Write a signal handler of SIGPIPE that just prints a message and returns. 
Establish this signal handler before calling connect. 
Change the server's port number to 13, the daytime server.
When the connection is established, sleep for two seconds,
write a few bytes to the socket, sleep for another two seconds, 
and write a few more bytes to the socket. Run the program. What happens?

