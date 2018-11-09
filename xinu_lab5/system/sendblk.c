// Import Libs
#include <xinu.h>

// Define System Call
syscall	sendblk(pid32 pid, umsg32 msg) {
	// Local Vars
	intmask	mask;			// Interrupt Mask			
	struct	procent *rprptr;	// Proctab Pointer Receiver
	struct	procent	*sprptr;	// Proctab Pointer Sender

	// Disable Interrupts
	mask = disable();

	// Check if Valid PID
	if(isbadpid(pid)) {
		// Enable Interrupts
		restore(mask);

		// Return Error
		return SYSERR;
	}

	// Get Process Entry
	rprptr = &proctab[pid];
	sprptr = &proctab[currpid];

	// Validate Entry
	if ((rprptr->prstate == PR_FREE)) {
		// Enable Interrupts
		restore(mask);

		// Return Error
		return SYSERR;
	}

	// Buffer Empty send as Normal
	if(rprptr->prhasmsg == FALSE) {
		// Enable Interrupts
		restore(mask);

		// Return Error
		return send(pid, msg);
	}

	// Stage Vars
	sprptr->sendblkflag = TRUE;
	sprptr->sendblkmsg = msg;
	sprptr->sendblkrcp = pid;
	
	// Change State
	sprptr->prstate = PR_SNDBLK;

	// Add to Q
	enqueue(currpid, rprptr->sendqueue);
	rprptr->rcpblkflag = TRUE;

	// Resched
	resched();

	// Enable Interrupts
	restore(mask);

	// Return OK
	return OK;
}
