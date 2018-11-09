// Import Libs
#include <xinu.h>

// Define System Call
umsg32 receive(void) {
	// Local Vars
	intmask mask;			// Interrupt Mask
	struct procent *rprptr;		// Proctab Pointer Reciever
	struct procent *sprptr;		// Proctab Pointer Sender
	umsg32 msg;			// Message

	// Disable Interrupts
	mask = disable();

	// Get Process
	rprptr = &proctab[currpid];
	
	// Block if No Message
	if (rprptr->prhasmsg == FALSE) {
		// Blocking State
		rprptr->prstate = PR_RECV;

		// Reschedule
		resched();
	}

	// Get Message
	msg = rprptr->prmsg;

	// Set hasMessage to False		
	rprptr->prhasmsg = FALSE;

	// Simple Receive
	if(rprptr->rcpblkflag == FALSE) {		
		// Enable Interrupts
		restore(mask);

		// Return Message
		return msg;
	}
	
	// Dequeue
	int senderPID = dequeue(rprptr->sendqueue);
	sprptr = &proctab[senderPID];

	// Stage Message
	rprptr->prmsg = sprptr->sendblkmsg;

	// Stage hasMessage		
	rprptr->prhasmsg = TRUE;

	// Clean Up
	sprptr->sendblkflag = FALSE;
	sprptr->sendblkmsg = 0;
	sprptr->sendblkrcp = 0;

	// If Empty
	if(isempty(rprptr->sendqueue))
		rprptr->rcpblkflag = FALSE;

	// Ready
	ready(senderPID);

	// Enable Interrupts
	restore(mask);

	// Return Message
	return msg;	
}
