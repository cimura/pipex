#include "../include/pipex.h"

#define OPEN_MAX 10000

// fd[0] -> STDIN read
// fd[1] -> STDOUT write

// outfileに権限がない場合に、エラーの出力がターミナルとは異なる


static void	child_process(int *fd, char *path, char **cmd, char **argv)
{
	int infile = open(argv[1], O_RDONLY);
	if (infile < 0 || infile >= OPEN_MAX)
	{
		perror("open infile");
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	// close(infile);
	close(fd[0]);

	// close(fd[1]);

	execve(path, cmd, NULL);
	perror("execve cmd1");
	exit(EXIT_FAILURE);
}

static void	parent_process(int *fd, char *path, char **cmd, char **argv)
{
	// close(fd[0]);

	int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	// close(outfile);
	execve(path, cmd, NULL);
	perror("execve cmd2");
	exit(EXIT_FAILURE);
}

void	ft_exec(int *fd, char *path1, char *path2, char *argv[])
{
	pid_t	pid;

	char **cmd1 = ft_split(argv[2], ' ');
	char **cmd2 = ft_split(argv[3], ' ');
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	// Child
	if (pid == 0)
		child_process(fd, path1, cmd1, argv);
	// Parent
	else
	{
		wait(NULL);
		parent_process(fd, path2, cmd2, argv);
	}
}

char *get_exec_path(char **paths, char **command)
{
	int	i;
	char	*path;

	i = 0;
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, command[0]);
		if (access(path, X_OK) == 0)
			break ;
		i++;
	}
	return (path);
}
