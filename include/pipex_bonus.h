/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:31:08 by cimy              #+#    #+#             */
/*   Updated: 2024/08/17 17:01:14 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"
# include "../srcs/get_next_line/get_next_line.h"

/*** multi_pipes ***/
void	loop_execute(char *argv[], int argc, char *envp[], t_file *file);

/*** here_doc ***/
void	here_doc(char *argv[], char *envp[]);

/*** utils ***/
int		open_file(const char *file, int flag);
void	print_usage2(void);

#endif