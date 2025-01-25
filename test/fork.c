#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

void sig_chld(int num)
{
	if (num == SIGCHLD)
	{
		printf("signal SIGCHLD\n");
	}
}

int main(int argc, const char *argv[])
{
	pid_t pid = 0;

	signal(SIGCHLD, sig_chld);

	pid = fork();
	printf("%d\n", pid);

	if (pid < 0)
	{
		printf("fork failed");
		return 1;
	}
	else if (pid == 0)
	{
		printf ("child process successfully created!\n");
		printf ("child_PID = %d,parent_PID = %d\n",
				getpid(), getppid());
	}
	else
	{
		printf("wait..\n");
		wait(NULL);
		printf ("parent process successfully created!\n");
		printf ("child_PID = %d, parent_PID = %d\n", getpid(), getppid());
		printf ("user_ID = %d\n", getuid());
	}

	return 0;
}
