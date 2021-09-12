# Exercise 7.4
Assume two TCP clients start at about the same time. Both set the SO\_REUSEADDR socket option and then call bind with the same local IP address and the same local port (say 1500). But, one client connects to 198.69.10.2 port 7000 and the second connects to 198.69.10.2 (same peer IP address) but port 8000. Describe the race condition that occurs.
