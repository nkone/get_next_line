/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:38:28 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/08 14:01:06 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	int fd2;
	char *line;
	char *line2;
	char *fname;
	char *fname2;

	fd = 0;
	fd2 = 0;
	fname = "./test.txt";
	fname2 = "./test2.txt";
	fd = open(fname, O_RDONLY);
	fd2 = open(fname2, O_RDONLY);
	printf("fd: %d\n", fd);
	printf("fd2: %d\n", fd2);
	/*
	 * Read with fd and print
	 */
	while(get_next_line(fd, &line))
		{
			printf("Line: |%s|\n", line);
			free(line);
			if (get_next_line(fd2, &line2))
				{
					printf("Line2: |%s|\n", line2);
					free(line2);
				}
		}
	while(1){} // leaks checking
	close(fd);
	close(fd2);
	return (0);
}
