/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:51:24 by cimy              #+#    #+#             */
/*   Updated: 2024/08/29 14:41:29 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_usage(void)
{
	ft_putstr_fd(RED"Bad arguments\n"RESET, 2);
	ft_putstr_fd("Usage:  \
  ./pipex infile <cmd1> <cmd2> outfile\n", 1);
	ft_putstr_fd("Example:\
  ./pipex infile cat \"ls -l\"  outfile\n", 1);
	exit(EXIT_FAILURE);
}

void	error_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	specific_error(char *command)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	by_path(char *command)
{
	if (command[0] == '/')
	{
		if (access(command, X_OK) != 0)
			error_exit(command);
		else if (access(command, F_OK) != 0)
		{
			ft_putstr_fd(command, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(127);
		}
	}
}
