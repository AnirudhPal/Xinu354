// Import Libs
#include <xinu.h>
#define	MSG	123

// Define Process
void sendblkproc(pid32 pid) {
	// Loop Infinitely
	while(1) {
		// Send Message
		sendblk(pid, MSG);

		// Print Message
		intmask mask = disable();
		kprintf("Sender (SENDBLK) -> %d ", MSG);
		restore(mask);				 
	}
}
