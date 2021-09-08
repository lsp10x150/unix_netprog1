start tcpdump with following: 
	tcpdump 'tcp and port chargen' -i "name_of_your_loopback_interface" (name of loopback can be found with tcpdump -D)
and then start the client in build directory
see packets in tcpdump
