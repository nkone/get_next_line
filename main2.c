/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:38:28 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/09 13:38:23 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

/*
 * Similar test to moulitest
 * Not sure why moulitest has "free" error
 */

int main()
{
	int fd;
	int fd2;
	char *line;
	char *line2;
	char *fname;
	char *fname2;
	int	ret, ret2;

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
	if (fd > 2 && fd2 > 2)
	{
		line = NULL;
		line2 = NULL;
		
		ret = get_next_line(fd, &line);
		if (ret!= 1)
			printf("error");
		printf("Line [fd]: |%s|\n", line);
		ret = get_next_line(fd, &line);
		if (ret != 1)
			printf("error");
		printf("Line [fd]: |%s|\n", line);
		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1)
			printf("error");
		printf("Line [fd2]: |%s|\n", line2);
		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1)
			printf("error");
		printf("Line [fd2]: |%s|\n", line2);
	}
	while(1){} // leaks checking
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
