/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:51:24 by cimy              #+#    #+#             */
/*   Updated: 2024/08/27 10:17:10 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_file	file;

	if (argc == 5)
	{
		file.in = open(argv[1], O_RDONLY, 0777);
		if (file.in == -1)
			perror(argv[1]);
		file.out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (file.out == -1)
			perror(argv[4]);
		if (argc == 5)
			parent(argv, envp, &file);
	}
	else
		print_usage();
	return (0);
}
