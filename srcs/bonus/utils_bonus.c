/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:05:16 by cimy              #+#    #+#             */
/*   Updated: 2024/08/17 16:55:07 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_usage2(void)
{
	ft_putstr_fd(RED"Bad arguments\n"RESET, 2);
	ft_putstr_fd("Usage:\
  ./pipex infile <cmd1> <cmd2> <cmd3> ... <cmdn> outfile\n", 1);
	ft_putstr_fd(" Or \n", 1);
	ft_putstr_fd("Usage:\
  ./pipex here_doc LIMITER <cmd> <cmd1> file\n", 1);
	exit(EXIT_FAILURE);
}

int	open_file(const char *file, int flag)
{
	int	fd;

	fd = -1;
	if (flag == HERE_DOC)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (flag == INFILE)
		fd = open(file, O_RDONLY, 0777);
	else if (flag == OUTFILE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		perror(file);
	return (fd);
}
