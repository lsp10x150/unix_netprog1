# Exercise 5.9
In our example in Figures 5.19 and 5.20, can we solve the byte ordering problem by having the client convert the two arguments into network byte order using htonl, having the server then call ntohl on each argument before doing the addition, and then doing a siilar conversion on the result?
