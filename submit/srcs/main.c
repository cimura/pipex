/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:01:55 by sshimura          #+#    #+#             */
/*   Updated: 2024/08/03 16:51:25 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char *argv[], char *envp[]) {
	if (argc == 5)
	{
		while (*envp)
		{
			if (!ft_strncmp(*envp, "PATH", 4))
				break ;
			envp++;
		}
		int	fd[2];

		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		
		char **paths = ft_split(*envp+5, ':');

		char **cmd1 = ft_split(argv[2], ' ');
		char **cmd2 = ft_split(argv[3], ' ');

		char *path1 = get_exec_path(paths, cmd1);
		char *path2 = get_exec_path(paths, cmd2);
		// printf("%s\n%s\n", path1, path2);

		ft_exec(fd, path1, path2, argv);
		return 0;
	}
}