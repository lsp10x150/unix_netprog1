This is a feature of some resolvers, but you cannot rely on it in a portable program because POSIX leaves the behavior unspecified. Fig E.11 shows the modified version. The order of the tests on the hostname string is important. We call inet\_pton first, as it is a fast. in-memory test for whether or not the string is a valid dotted-decimal IP address. Onlly if this fails do we call gethostbyname, which typically involves some network resources and some time.
If the string is a valid dotted-decimal IP address, we make our own array of pointers to the single IP address, allowing the loop using pptr to remain the same.
Since the address has already been converted to binary in the socket address structure, we change the call to memcpy in Fig 11.4 to call memmove instead, because when a dotted-decimal IP address is entered, the source and destination fields are the same in this call.