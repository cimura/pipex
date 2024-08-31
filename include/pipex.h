/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:35:02 by sshimura          #+#    #+#             */
/*   Updated: 2024/08/31 18:08:31 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../srcs/libft/libft.h"

// *** color ***
# define RED     "\x1B[31m"
# define RESET   "\x1B[0m"

// *** for open file ***
# define HERE_DOC 1
# define INFILE 2
# define OUTFILE 3

typedef struct s_file
{
	int	in;
	int	out;
}		t_file;

// *** util ***
void	parent(char *argv[], char *envp[], t_file *file);
void	execute_cmd(char *argv, char *envp[]);
void	free_str_array(char **ddptr);

// *** error ***
void	error_exit(const char *message);
void	print_usage(void);
void	specific_error(char *command);
void	by_path(char *command);

// *** clear ***
void	clear_parent(t_file *file);

// *** get_path ***
char	*get_exec_path(char **paths, char **command, char **envp);
char	**setup_paths(char *envp[]);

#endif