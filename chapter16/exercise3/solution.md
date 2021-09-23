When the child calls getppid to send SIGTERM to the parent, the returned PID will be 1, the init process, which inherits all children whose parents terminate while their children are still running. The child will try to send the signal to the init process, but will not have adequate permission. But if there is a chance that this client could run with superuser privileges, allowing it to send this signal to init, then the return value of getppid should be tested before sending the signal.