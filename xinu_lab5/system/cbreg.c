// Import Libs
#include <xinu.h>

// Define System Call
syscall	cbreg(int (* fnp) (void)) {
	// Local Vars
	intmask	mask;			// Interrupt Mask			
	struct	procent *rprptr;	// Proctab Pointer Receiver

	// Disable Interrupts
	mask = disable();

	// Get Process Entry
	rprptr = &proctab[currpid];

	// Validate Entry
	if ((rprptr->prhascb == TRUE)) {
		// Enable Interrupts
		restore(mask);

		// Return Error
		return SYSERR;
	}

	// Set Function Pointer
	rprptr->fptr = fnp;

	// Set Flag
	rprptr->prhascb = TRUE;
	
	// Enable Interrupts
	restore(mask);

	// Return OK
	return OK;
}
