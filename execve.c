#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char	*const args[] = {"ls", "-al", NULL};
	char	*const envp[] = {NULL};

	execve("/usr/bin/ls", args, envp);

	perror("execve");
	return (1);
}