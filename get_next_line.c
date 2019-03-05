/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/05 15:13:55 by phtruong         ###   ########.fr       */
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
** Find a way to null-termintate garbages.✓
** Maybe forget bonus✓
** Check for FD_LIMIT
** Make test for two/ may be three files
*/

#include "get_next_line.h"
#include "./libft/libft.h"

int	token_me(char **tmp, char **line)
{
	char *tmp_h;
	char *token;

	if (!**tmp)
		return (0);
	token = ft_strtok_r(*tmp, "\n", &*tmp);
	if (token != NULL)
	{
		*line = ft_strdup(token);
		tmp_h = ft_strdup(*tmp);
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
		ft_strclr(*tmp);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			n_bytes;
	static char	*tmp[FD_LIMIT];
	char		*tmp_h;

	if (fd == -1 || fd > FD_LIMIT || read(fd, buffer, 0) == -1)
		return (-1);
	if (!(tmp[fd]))
		tmp[fd] = ft_strnew(0);
	while (ft_strchr(tmp[fd], '\n') == NULL)
	{
		n_bytes = read(fd, buffer, BUFF_SIZE);
		buffer[n_bytes] = '\0';
		if (n_bytes == 0)
			break ;
		tmp_h = ft_strjoin(tmp[fd], buffer);
		free(tmp[fd]);
		tmp[fd] = ft_strdup(tmp_h);
		if (!(tmp[fd]))
			tmp[fd] = ft_strnew(0);
		free(tmp_h);
	}
	return (token_me(&tmp[fd], line));
}
