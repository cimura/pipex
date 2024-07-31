#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *cmd[] = {"/usr/bin/which", argv[2], NULL};
	execve(cmd[0], cmd, NULL);
	return (0);
}

// __attribute__((destructor))
// static void find_command() {
// 	system("which ls");
// }