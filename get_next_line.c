/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/04 08:32:23 by phtruong         ###   ########.fr       */
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
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	token_me(char **tmp, char **line)
{
	char *tmp_h;
	char *token;

	if (!*tmp)
		return (0);
	token = ft_strtok_r(*tmp, "\n", &*tmp);
	if (token != NULL)
	{
		*line = (char *)malloc(ft_strlen(token) * sizeof (char));
		ft_strcpy(*line, token);
		tmp_h = ft_strdup(*tmp);
		if (tmp_h)
		{
			*tmp = ft_strdup(tmp_h);
			free(tmp_h);
		}
		free (token);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		n_bytes;
	static char	*tmp[FD_LIMIT];
	char	*tmp_h;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(0);
	while (!(ft_strchr(tmp[fd], '\n')))
	{
		n_bytes = read(fd, buffer, BUFF_SIZE);
		if (n_bytes == 0)
			return (0);
		tmp_h = ft_strjoin(tmp[fd], buffer);
		free(tmp[fd]);
		tmp[fd] = ft_strdup(tmp_h);
		if(!tmp[fd])
			tmp[fd] = ft_strnew(0);
		free(tmp_h);
	}
	return (token_me(&tmp[fd], line));
}


/*int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc!=2)
		return (0); 
	if (argc == 2)
		fd = open (argv[1], O_RDONLY);
	whileread_me(fd, &line);
	printf("Line: |%s|\n", line);
	//free(line);
	if (argc == 2)
		close(fd);
	while(1){}
	return 0;
}
*/

