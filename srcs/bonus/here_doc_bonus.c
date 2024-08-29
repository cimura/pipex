/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:42:53 by cimy              #+#    #+#             */
/*   Updated: 2024/08/17 18:22:17 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	heredoc_child(char *argv[], char *envp[]
, int pipe_fd[2], const char *tmp_file)
{
	int	fd_tmp;

	fd_tmp = open(tmp_file, O_RDONLY);
	if (fd_tmp == -1)
		error_exit("tmpfile");
	unlink(tmp_file);
	dup2(fd_tmp, STDIN_FILENO);
	close(fd_tmp);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(argv[3], envp);
	exit(EXIT_FAILURE);
}

static void	heredoc_parent(char *argv[], char *envp[]
, int pipe_fd[2], pid_t pid)
{
	int	file_out;

	file_out = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (file_out == -1)
		error_exit("outfile");
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	execute_cmd(argv[4], envp);
	waitpid(pid, NULL, 0);
}

static void	heredoc_family(char *argv[], char *envp[], const char *tmp_file)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	pid = fork();
	if (pid == -1)
		error_exit("fork");
	if (pid == 0)
		heredoc_child(argv, envp, pipe_fd, tmp_file);
	heredoc_parent(argv, envp, pipe_fd, pid);
}

void	here_doc(char *argv[], char *envp[])
{
	char		*line;
	int			fd_tmp;
	const char	*tmp_file = "/tmp/.heredoc_tmp";

	fd_tmp = open(tmp_file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd_tmp == -1)
		error_exit("tmpfile");
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line || ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
			break ;
		write(fd_tmp, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd_tmp);
	heredoc_family(argv, envp, tmp_file);
}
