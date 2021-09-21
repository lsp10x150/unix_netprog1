If the sctp\_senndmsg function returns an error, no message will be sent and the application would then do a blocking sctp\_recvmsg, waiting for a respons message that would never be sent to it.
A way to fix this is to check the error return codes, and if an error occurs on sending, the client should NOT do the receive, but instead should report an error. 
If the sctp\_recvmsg function returns an error, no message will arrive and the server will still attempte to send a message, possibly setting up an association. To avoid this, the error code should be checked, and depending on the error, you may wish to report the error and close the socket, letting the server also then receive an error; or, if the error is transient, you could retry the sctp\_recvmsg call.