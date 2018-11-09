// Import Libs
#include <xinu.h>

// Define Process
void senddone(pid32 pid, umsg32 msg) {
	// Print Message
	intmask mask = disable();
	kprintf("PID: %d Sender (SENDBLK) -> %d to PID: %d\n", currpid, msg, pid);
	restore(mask);

	// Send Message
	sendblk(pid, msg);

	// Print Message
	mask = disable();
	kprintf("PID: %d Sender (SENDBLK) Done Sending \n", currpid);
	restore(mask);				 
}
