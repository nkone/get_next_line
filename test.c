/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:36:02 by phtruong          #+#    #+#             */
/*   Updated: 2019/03/04 09:34:07 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** String tokenizer
** We are here to test the posibilities of tokens :)
*/
/*
** Problems to fix: free leaks
** Can I free the temp? Maybe string duplicate for tokens?
** Make better variables than temp and temp_hold
** How to free and what it does?
*/
/*
// tokenize if there is new line
int	token_me(char **tmp, char **line)
{
	char *tmp_h;
	char *token;

	if (!*tmp)
		return (0);
	token = ft_strtok_r(*tmp, "\n", &*tmp);
	if (token != NULL)
	{
		*line = (char *)malloc(ft_strlen(token) * sizeof(char));
		ft_strcpy(*line, token);
		printf("tmp after token: |%s|\n", *tmp);
		tmp_h = ft_strdup(*tmp);
		if (tmp_h)
		{
			*tmp = ft_strdup(tmp_h);
			free(tmp_h);
		}
		free (token);
	}
	return (1);
}*/
/*int main()
{
	char *str_sp = "a b c d e f g";
	char str_nl[] = "a\nb\nc\nd\ne\nf\ng";
	char str_hd[] = "a, b, c, d, e, f, g\0I'm hidden lol\0";
	char *str_null = "\0Find me if you can\0";
	char *token;
	char *p_s;
	char *delim;

	delim = "\n";
	p_s = str_nl;
	while (token != NULL)
	{
		token = ft_strtok_r(p_s, delim, &p_s);
		printf("token: |%s|\n", token);
		printf("str_nl: |%s|\n", p_s);
	}
	return 0;
}*/
/*
int		gtfoline(char **holder, char **line)
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
}

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
			break ;
		tmp = ft_strjoin(arr[fd], buffer);
		free(arr[fd]);
		arr[fd] = ft_strdup(tmp);
		if (!(arr[fd]))
			arr[fd] = ft_strnew(0);
		free(tmp);
	}
	return (gtfoline(&arr[fd], line));
}
int	read_me(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		n_bytes;
	static char	*tmp[FD_LIMIT];
	char	*tmp_h;

//	check if there is new line in temp before read more
	if (fd < 0 || !line)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(0);
	while (!(ft_strchr(tmp[fd], '\n')))
	{
		n_bytes = read(fd, buffer, BUFF_SIZE);
	//	printf("n_bytes: %d\n", n_bytes);
		buffer[n_bytes] = '\0';
		if (n_bytes == 0)
			return (0);
		tmp_h = ft_strjoin(tmp[fd], buffer);
		free(tmp[fd]);
		tmp[fd] = ft_strdup(tmp_h);
		if (!(tmp[fd]))
			tmp[fd] = ft_strnew(0);
		free(tmp_h);
	//	tmp[fd] = ft_strdup(tmp_h);
		//free(tmp_h);
		printf("temp + buffer: |%s|\n", tmp[fd]);
	}
	return (token_me(&tmp[fd], line));
}	
*//*
int	get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		n_bytes;
	static char	*tmp[FD_LIMIT];
	char	*tmp_h;
	char	*token;

	if (fd < 0 || !line)
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
	if (!tmp[fd])
		return (0);
	token = ft_strtok_r(tmp[fd], "\n", &tmp[fd]);
	if (token != NULL)
	{
		*line = (char *)malloc(ft_strlen(token) * sizeof(char));
		ft_strcpy(*line, token);
		tmp_h = ft_strdup(tmp[fd]);
		if (tmp_h)
		{
			tmp[fd] = ft_strdup(tmp_h);
			free(tmp_h);
		}
		free (token);
	}
	return (1);
}
*/
int	main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc !=2)
		return (0);
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("Line: |%s|\n", line);
		free(line);
	}
	while (1){}
	if (argc == 2)
		close(fd);
	return (0);
}
