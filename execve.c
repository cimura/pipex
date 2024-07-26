#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"

// Usage    ->    ./pipex infile "ls -l" "wc -l" outfile
 
int main(int argc, char *argv[])
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	// *** Child *** //
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(2);
		printf("I waited 2s.\n");
		printf("Child process terminated after a 2s delay.\n");
		// exit(EXIT_SUCCESS);
	}
	// *** Parent *** //
	else
	{
		char **cmd1;
		
		cmd1 = ft_split(argv[2], ' ');
		// do argv[2] command
		// execve("/bin/ls", cmd1, NULL);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}