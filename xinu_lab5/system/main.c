/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

process	main(void)
{
	/** Message **/
	kprintf("(Pal, Anirudh)\n");
	kprintf("pal5\n");
	kprintf("All tests performed have been commented out in main.c\n");

	/** Start of Lab 5 **/
	// Sanity Check
	//resume(create(recvproc, 2042, 10, "recvproc", 0));
	//resume(create(sendblkproc, 2042, 10, "sendblkproc", 1, 3));

	// Blocking Receive
	//resume(create(recvproc, 2042, 15, "recvproc", 0));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 1213));

	// Blocking Sender
	//resume(create(recvslug, 2042, 10, "recvslug", 0));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 1213));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 2324));

	// Mutiple Sender
	//resume(create(recvslug, 2042, 10, "recvslug", 0));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 1213));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 2324));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 3435));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 4546));
	//resume(create(senddone, 2042, 10, "senddone", 2, 3, 5657));

	// Callback Receiver Interrupt 
	resume(create(recvcb, 2042, 10, "recvcb", 0));
	resume(create(senddoneog, 2042, 10, "senddoneog", 2, 3, 1213));
	//resume(create(senddoneog, 2042, 10, "senddoneog", 2, 3, 2324));	

	// Callback Receiver Sleeping 
	//resume(create(recvcbslp, 2042, 10, "recvcbslp", 0));
	//resume(create(senddoneog, 2042, 10, "senddoneog", 2, 3, 1213));
	//resume(create(senddoneog, 2042, 10, "senddoneog", 2, 3, 2324));	

	// Terminating Receive
	/** End of Lab 5 **/

	/**
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	**/

	return OK;
}
