A selective acknowledgment only indicates that the data covered by the sequence numbers reflected in the selective acknowledgment says that the data up to and including the sequence number in the cumulative acknowledgment message was received. When freeing data from the send buffer based on a selective acknowledgment, the system may only free the exact data that was acknowledged, and not any before or after the selective acknowledgement.