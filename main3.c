/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:07:58 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/09 13:37:25 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Test big fat line 60k of characters
 */

int main()
{
	int fd;
	char *line;
	char *filename;

	filename = "./one_big_fat_line.txt";
	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
