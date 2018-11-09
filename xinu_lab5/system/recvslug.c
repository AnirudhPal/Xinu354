// Import Libs
#include <xinu.h>

// Define Process
void recvslug() {
	// Sleep
	sleep(1);

	// Get Message
	int res = (int) receive();

	// If Recieve
	intmask mask = disable();
	kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
	restore(mask);

	// Get Message
	res = (int) receive();

	// If Recieve
	mask = disable();
	kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
	restore(mask);

	// Get Message
	res = (int) receive();

	// If Recieve
	mask = disable();
	kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
	restore(mask);

	// Get Message
	res = (int) receive();

	// If Recieve
	mask = disable();
	kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
	restore(mask);

	// Get Message
	res = (int) receive();

	// If Recieve
	mask = disable();
	kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
	restore(mask);

	// Get Message
	res = (int) receive();

	// If Recieve
	mask = disable();
	kprintf("PID: %d Receiver (RECEIVE) <- %d\n", currpid, res); 
	restore(mask);

}
