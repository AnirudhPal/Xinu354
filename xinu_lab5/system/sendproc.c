// Import Libs
#include <xinu.h>

#define	MSG	123

// Define Process
void sendproc(pid32 pid) {
	// Loop Infinitely
	while(1) {
		// Send Message
		int res = send(pid, MSG);

		// If Sent
		if(res != SYSERR) {
			intmask mask = disable();
			kprintf("Sender (SEND) -> %d ", MSG);
			restore(mask);
		}					 
	}
}
