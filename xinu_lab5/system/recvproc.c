// Import Libs
#include <xinu.h>

// Define Process
void recvproc() {
	// Loop Infinitely
	while(1) {
		// Get Message
		int res = (int) receive();

		// If Recieve
		intmask mask = disable();
		kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
		restore(mask);
	}
}
