/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:43:57 by cimy              #+#    #+#             */
/*   Updated: 2024/08/31 18:06:46 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char *envp[])
{
	char	**paths;
	char	*path;
	char	**command;

	paths = setup_paths(envp);
	command = ft_split(argv, ' ');
	path = get_exec_path(paths, command, envp);
	if (path == NULL)
	{
		specific_error(command[0]);
		free_str_array(paths);
		free_str_array(command);
		exit(127);
	}
	if (execve(path, command, envp) == -1)
	{
		perror(command[0]);
		if (path != command[0])
			free(path);
		free_str_array(paths);
		free_str_array(command);
		exit(EXIT_FAILURE);
	}
}

static void	child1_process(char *argv[], char *envp[], t_file *file, int fd[2])
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(file->in, STDIN_FILENO);
	if (file->in != -1)
		execute_cmd(argv[2], envp);
	exit(EXIT_FAILURE);
}

static void	child2_process(char *argv[], char *envp[], t_file *file, int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(file->out, STDOUT_FILENO);
	if (file->out != -1)
		execute_cmd(argv[3], envp);
	exit(EXIT_FAILURE);
}

void	parent(char *argv[], char *envp[], t_file *file)
{
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork");
	if (pid1 == 0)
		child1_process(argv, envp, file, fd);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork");
	if (pid2 == 0)
		child2_process(argv, envp, file, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	clear_parent(file);
	exit(WEXITSTATUS(status));
}
