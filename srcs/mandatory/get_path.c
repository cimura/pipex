/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:43:57 by cimy              #+#    #+#             */
/*   Updated: 2024/09/01 11:46:05 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_check(char **paths, char **command, char **envp)
{
	if (!command || !*command)
	{
		specific_error("");
		exit(127);
	}
	if (command[0][0] == '/' || command[0][0] == '.')
	{
		if (execve(command[0], command, NULL) != -1)
			exit (EXIT_SUCCESS);
		// ./pipex infile cat ./cat cat outこれがうまくいかない
		if (execve(command[0], command, envp) != -1)
			exit (EXIT_SUCCESS);
		perror(command[0]);
		exit(127);
	}
	if (paths == NULL)
	{
		ft_putstr_fd(command[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	by_path(command[0]);
}

char	*get_exec_path(char **paths, char **command, char **envp)
{
	int		i;
	char	*path;
	char	*before_join;

	i = 0;
	error_check(paths, command, envp);
	while (paths[i] != NULL)
	{
		before_join = ft_strjoin(paths[i], "/");
		path = ft_strjoin(before_join, command[0]);
		free(before_join);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**setup_paths(char *envp[])
{
	char	**paths;

	if (!envp || !*envp)
		return (NULL);
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
			break ;
		envp++;
	}
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	return (paths);
}
