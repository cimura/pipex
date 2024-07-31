#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

// fd[0] -> STDIN read
// fd[1] -> STDOUT write

void    ft_exec()
{
	int fd[2];
	pid_t pid;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	// Child
	if (pid == 0)
	{
		int infile = open("infile", O_RDONLY);
		if (infile == -1)
		{
			perror("open infile");
			exit(EXIT_FAILURE);
		}
		dup2(infile, STDIN_FILENO);
		close(infile);
		close(fd[0]);

		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);

		char *args1[] = {"/usr/bin/cat", NULL};
		execve("/usr/bin/cat", args1, NULL);
		perror("execve");
		return ;
	}
	// Parent
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);

		int outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
		{
			perror("open outfile");
			exit(EXIT_FAILURE);
		}
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		char *args2[] = {"/usr/bin/wc", NULL};
		execve("/usr/bin/wc", args2, NULL);
		perror("execve");
		return ;
	}
}

int main() {
	ft_exec();
}
