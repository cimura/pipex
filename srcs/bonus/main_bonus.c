/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:51:24 by cimy              #+#    #+#             */
/*   Updated: 2024/08/31 15:46:24 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_file	file;

	if (argc == 6 && (!(ft_strncmp("here_doc", argv[1], 8))))
		here_doc(argv, envp);
	file.in = open_file(argv[1], INFILE);
	file.out = open_file(argv[argc - 1], OUTFILE);
	if (argc == 5)
		parent(argv, envp, &file);
	else if (argc >= 6)
	{
		dup2(file.in, STDIN_FILENO);
		loop_execute(argv, argc, envp, &file);
	}
	else
		print_usage2();
	return (0);
}
