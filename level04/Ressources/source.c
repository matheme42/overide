#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
	int		fk;
	char	buffer[32];
	int		w;

	fk = fork();
	bzero(buffer, sizeof(buffer));
	
	w = 0;
	if (fk == 0)
	{
        ptrace(0, 0, 0, 0);
        printf("Give me some shellcode, k\n");
        gets(buffer);
	}
	else
	{
		wait(&w);
		printf("child is exiting...\n");
		kill(fk, 9);
	}
	return (0);
}