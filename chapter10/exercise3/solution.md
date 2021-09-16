We choose 800 bytes to attempt to geteach chunk in a single packet. A bbetter way would be to get or set the SCTP\_MAXSEG socket option to determine the size that will fit in one chunk.
