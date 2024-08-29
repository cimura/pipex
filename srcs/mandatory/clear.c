/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:27 by cimy              #+#    #+#             */
/*   Updated: 2024/08/29 14:51:00 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str_array(char **ddptr)
{
	int	i;

	i = 0;
	while (ddptr[i] != NULL)
		free(ddptr[i++]);
	free(ddptr);
}

void	clear_parent(t_file *file)
{
	close(file->in);
	close(file->out);
}
