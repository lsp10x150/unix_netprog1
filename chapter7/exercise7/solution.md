-d     Set the SO\_DEBUG option on the socket being used.   Essentially,  this socket option is not used by Linux kernel.
ANSWER: This does nothing because ping uses an ICMP socket and the SO\_DEBUG socket option has always been something generic such as "this option enables debugging in the respective protovol layer", but the only protocol layer to implement the option has been TCP.
