I don't see how this is possible, because chid will kill it's parent with SIGTERM.
The parent will keep writiing to the socket that has recieved a FIN, and the first segment sent to the server will elicit an RST in response. The next write after this will send SIGPIPE to the parent as we discussed in Section 5.12
