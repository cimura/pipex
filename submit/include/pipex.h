/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:35:02 by sshimura          #+#    #+#             */
/*   Updated: 2024/08/03 16:51:06 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include "../srcs/libft/libft.h"

char	*get_exec_path(char **paths, char **command);
void	ft_exec(int *fd, char *path1, char *path2, char *argv[]);
// void	child_process(int *fd, char *path, char **cmd);
// void	parent_process(int *fd, char *path, char **cmd);