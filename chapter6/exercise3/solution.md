Adding else will make our code less efficient, because on each return of select only one event will be processed: either read or write.
The key concept here is that what clears the condition of 'standard input being readable' is not select returning, but reading from the descriptor.
