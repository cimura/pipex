#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
 #include <sys/wait.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        printf("Child -> %d\n", pid);
        printf("Child: I'm the child, my internal pid is %d.\n", pid);
        printf("Child: Done!\n");
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("Parent -> %d\n", pid);
        printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
        int fd = open("readfile", O_RDONLY);
        printf("fd is %d\n", fd);
        // while (1) // Infinite loop, the parent will never end !
        //     usleep(1);
    }
    return (0);
}