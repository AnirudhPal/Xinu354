// Import Libs
#include <xinu.h>

// Global Var
volatile umsg32 mbufslp = 0;

// Define Callback
int32 mrecv_cbslp(void) {
	// Get Message
	mbufslp = receive();

	// Print Message
	intmask mask = disable();
	kprintf("PID: %d Receiver CallBack (CALLBACK) <- %d\n", currpid, mbufslp); 
	restore(mask);

	// Return
	return(OK);
}

// Define Process
void recvcbslp() {
	// Register Callback
	if (cbreg(&mrecv_cbslp) != OK) {
		kprintf("cb registration failed!");
		return;
	}

	sleep(10);

	// Infinite Loop
	while(1) {
		// Print Message
		intmask mask = disable();
		kprintf("PID: %d Receiver (CALLBACK) <- %d\n", currpid, mbufslp); 
		restore(mask);
	}
}
