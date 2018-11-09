// Import Libs
#include <xinu.h>

// Define Handler
void cbhandler() {
	// Get Process
	struct procent* prptr = &proctab[currpid];

	// Check if Message & Callback
	if(prptr->prhasmsg && prptr->prhascb) {
		// Call Callback
		prptr->fptr();
	}
}
