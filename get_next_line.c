/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:21:36 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/28 18:50:13 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** This is a function that returns a line read from a file descriptor
*/

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	read_me(int const fd, char **line)
{

	char	buffer[BUFF_SIZE + 1];
	int		fd_no;

	while (!(ft_strchr(*line, '\n')))
	{
		fd_no = read(fd, buffer, BUFF_SIZE);
		if (fd_no == -1)
			return (fd_no);
		buffer[BUFF_SIZE] = '\0';
		*line = ft_strjoin(*line, buffer);
		ft_memdel((void *)&buffer);
	}
	return (0);
}
int main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
		fd = 0;
	if (argc == 2)
		fd = open (argv[1], O_RDONLY);
	char *token;
	char *temp;
	char buff[BUFF_SIZE + 1];	
	temp = "";
	while (read(fd, buff, BUFF_SIZE))
	{
		temp = ft_strjoin(temp, buff);
	}
	while (*temp)
	{
		token = ft_strtok_r(temp, "\n", &temp);
		printf("line: |%s|\n", token);
	}
	printf("temp: |%s|\n", temp);
	if (argc == 2)
		close(fd);
	return 0;
}


