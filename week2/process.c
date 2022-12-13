#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	int liCt =0;
	pid_t pid;

	printf("PID is %d \n", getpid());
	pid = fork();

	switch(pid)
	{
		case -1:
			printf("error : PID created fail!!\n");
      return -1;

		case 0:
			printf("PID is %d and PPID is %d \n", getpid(), getppid());
			break;

		default:
			printf("PPID is %d \n", getpid());
	}
}

