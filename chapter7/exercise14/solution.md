The client spends most of its time blocked in the call to select, which will return the socket as readable as soon as the pending error is set to ETIMEDOUT (as we described in the previous solution).
