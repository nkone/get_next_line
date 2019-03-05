/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/04 10:55:08 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** This is a function that returns a line read from a file descriptor
*/

/*
** GENERAL INFO
** read function returns a non-negative integer indicating no. bytes read
** otherwise -1, indicating error.
** Find a way to null-termintate garbages.
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/*int	token_me(char **tmp, char **line)
{
	char *tmp_h;
	char *token;

	if (!**tmp)
		return (0);
	token = ft_strtok_r(*tmp, "\n", &*tmp);
	if (token != NULL)
	{
		*line = (char *)malloc(ft_strlen(token) * sizeof(char *));
		ft_strcpy(*line, token);
		tmp_h = ft_strdup(*tmp);
		//printf("tmp_h: |%s|\n", tmp_h);
		if (tmp_h)
		{
			*tmp = ft_strdup(tmp_h);
			free(tmp_h);
		}
		free(token);
	}
	else
	{
		*line = ft_strdup(*tmp);
		ft_memdel((void **)*tmp);
	}
	return (1);
}*/

int		token_me(char **holder, char **line)
{
	char *tmp;

	if ((*holder)[0] == '\0')
		return (0);
	if (ft_strchr(*holder, '\n') != NULL)
	{
		*(ft_strchr(*holder, '\n')) = '\0';
		*line = ft_strdup(*holder);
		tmp = ft_strdup(ft_strchr(*holder, '\0') + 1);
		free(*holder);
		if (tmp)
		{
			*holder = ft_strdup(tmp);
			free(tmp);
		}
	}
	else
	{
		*line = ft_strdup(*holder);
		ft_memdel((void **)holder);
	}
	return (1);
}/*
int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			n_bytes;
	static char	*tmp[FD_LIMIT];
	char		*tmp_h;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(0);
	while (!(ft_strchr(tmp[fd], '\n')))
	{
		n_bytes = read(fd, buffer, BUFF_SIZE);
		if (n_bytes == 0)
			break;
		buffer[BUFF_SIZE] = '\0';
		tmp_h = ft_strjoin(tmp[fd], buffer);
		free(tmp[fd]);
		tmp[fd] = ft_strdup(tmp_h);
		if (!tmp[fd])
			tmp[fd] = ft_strnew(0);
		free(tmp_h);
	}
	return (token_me(&tmp[fd], line));
}*/
int		get_next_line(const int fd, char **line)
{
	int			br;
	char		buffer[BUFF_SIZE + 1];
	static char	*arr[FD_LIMIT];
	char		*tmp;

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	if (!(arr[fd]))
		arr[fd] = ft_strnew(0);
	while (ft_strchr(arr[fd], '\n') == NULL)
	{
		br = read(fd, buffer, BUFF_SIZE);
		buffer[br] = '\0';
		if (br == 0)
			break;
		tmp = ft_strjoin(arr[fd], buffer);
		free(arr[fd]);
		arr[fd] = ft_strdup(tmp);
		if (!(arr[fd]))
			arr[fd] = ft_strnew(0);
		free(tmp);
	}
	return (token_me(&arr[fd], line));
}
