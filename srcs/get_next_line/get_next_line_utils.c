/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:28 by sshimura          #+#    #+#             */
/*   Updated: 2024/08/09 08:02:32 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	ssize_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	str_len;

	str_len = ft_strlen((char *)str);
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, (char *)str);
	return (result);
}

char	*ft_strjoin(char const *leftover, char const *buf)
{
	char	*result;
	size_t	leftover_len;
	size_t	buf_len;

	if (leftover == NULL && buf == NULL)
		return (NULL);
	leftover_len = ft_strlen(leftover);
	buf_len = ft_strlen(buf);
	result = (char *)malloc(sizeof(char) * (leftover_len + buf_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, (char *)leftover);
	ft_strcpy(result + leftover_len, (char *)buf);
	return (result);
}
