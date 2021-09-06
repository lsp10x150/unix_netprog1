In discussing SCTP output, we said that the SCTP sender must wait for the cumulative acknowledgment point to pass sent data before the data could be freed from the socket buffer. If a selective acknowledgment shows that data is acknowledged beyond the cumulative acknowledgment point, why can't the data be freed?