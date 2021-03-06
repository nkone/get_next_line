/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:38:28 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/09 13:56:07 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

/*
 * Multiple files test
 * i.txt has numbers for index
 * q.txt has questions
 * a.txt has answers
 */

int main()
{
	int fd;
	int fd2;
	int fd3;
	char *line;
	char *line2;
	char *line3;
	char *fname;
	char *fname2;
	char *fname3;

	fd = 0;
	fd2 = 0;
	fname = "./i.txt";
	fname2 = "./q.txt";
	fname3 = "./a.txt";
	fd = open(fname, O_RDONLY);
	fd2 = open(fname2, O_RDONLY);
	fd3 = open(fname3, O_RDONLY);
	printf("fd: %d fd2: %d fd3: %d\n", fd, fd2, fd3);
	/*
	 * Read with fd and print
	 */
	while(get_next_line(fd, &line) > 0)
		{
			//printf("|#%s.| ", line);
			if (get_next_line(fd2, &line2) > 0)
				{
					printf("Question %s: |%s|\n", line, line2);
					free(line);
					free(line2);
					if (get_next_line(fd3, &line3) > 0)
						printf("Answer: |%s|\n", line3);
					free(line3);
				}
		}
	while(1){} // leaks checking
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
