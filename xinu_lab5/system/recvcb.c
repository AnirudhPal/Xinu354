// Import Libs
#include <xinu.h>

// Global Var
volatile umsg32 mbuf = 0;

// Define Callback
int32 mrecv_cb(void) {
	// Get Message
	mbuf = receive();

	// Print Message
	while(1) {
	intmask mask = disable();
	kprintf("PID: %d Receiver CallBack (CALLBACK) <- %d\n", currpid, mbuf); 
	restore(mask);
	}

	// Return
	return(OK);
}

// Define Process
void recvcb() {
	// Register Callback
	if (cbreg(&mrecv_cb) != OK) {
		kprintf("cb registration failed!");
		return;
	}

	//sleep(10);

	// Infinite Loop
	while(1) {
		// Print Message
		intmask mask = disable();
		kprintf("PID: %d Receiver (CALLBACK) <- %d\n", currpid, mbuf); 
		restore(mask);
	}
}
