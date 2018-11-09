// Import Libs
#include <xinu.h>

// Define Process
void senddoneog(pid32 pid, umsg32 msg) {
	// Print Message
	intmask mask = disable();
	kprintf("PID: %d Sender (SEND) -> %d to PID: %d\n", currpid, msg, pid);
	restore(mask);

	// Send Message
	send(pid, msg);

	// Print Message
	while(1){
	mask = disable();
	kprintf("PID: %d Sender (SEND) Done Sending \n", currpid);
	restore(mask);
	}			 
}
