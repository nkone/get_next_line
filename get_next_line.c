/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/09 13:42:08 by phtruong         ###   ########.fr       */
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
** Check for FD_LIMIT✓
** Make test for two/ may be three files ✓
** Add fd for token_me function so I can access index directly ✓
*/

#include "get_next_line.h"

/*
** PSEUDOCODE
** Collects input from main function
** Check if array is null
** Cut into tokens based on newline
** Copy token into line
** Copy what's left over into middle ground to free
** Free token pointer
*/

int	token_me(char **tmp, char **line, int fd)
{
	char *tmp_h;
	char *token;

	if (!*tmp[fd])
		return (0);
	token = ft_strtok_r(tmp[fd], "\n", &tmp[fd]);
	if (token != NULL)
	{
		*line = ft_strdup(token);
		tmp_h = ft_strdup(tmp[fd]);
		if (tmp_h)
		{
			tmp[fd] = ft_strdup(tmp_h);
			free(tmp_h);
		}
	}
	else
		*line = ft_strdup(tmp[fd]);
	free(token);
	return (1);
}

/*
** PSEUDOCODE
** Check for fd false cases, FD_LIMIT (use ulimit -a to check)
** Allocate new memory to read string into static array
** While checking for newline in that array
** Read into and join what has read into that array
** Free using middle ground tmp_h (copy back and forth)
** Extend the fucntion
*/

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
		tmp_h = tmp[fd];
		tmp[fd] = ft_strjoin(tmp[fd], buffer);
		free(tmp_h);
	}
	return (token_me(tmp, line, fd));
}
