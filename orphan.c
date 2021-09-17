#include <stdio.h>
#include <unistd.h>
int main(){
	// creates the child process
	int pid = fork();
	if(pid > 0)
		// the parent process is put to sleep for 30 secs which is enough time to
		// open top and check the PPID of the child process and confirm it is the parent process
		sleep(30);
	else if(pid == 0)
		// after the 30 secs are over, child process will be an orphan for 90 - 30 = 60 seconds
		// so in those 60 seconds, we can see that the PPID of the child is 1
		sleep(90);
	return 0;
}

