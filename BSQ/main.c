/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:27:35 by rnovotny          #+#    #+#             */
/*   Updated: 2022/11/02 17:28:42 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		chartoint(char *lines);

int		checklines(char **map, int lines, char *chars);

void	printresult(char **map, int lines);

int		getwidth(char **map, int lines);

int		**matrix(char **matrix, char *chars, int h, int w);

void	solve(char **map, int height, char *chars);

int	loadmap(int fd, char *chars, char **map, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		map[i] = (char *)malloc(sizeof(char) * 4096);
		j = -1;
		while ((j == -1 || map[i][j] != '\n') && j < 4096)
		{
			j++;
			read(fd, &map[i][j], 1);
		}
		i++;
	}
	if (checklines(map, lines, chars))
	{
		while (i-- > 0)
			free(map[i]);
		return (1);
	}
	solve(map, lines, chars);
	while (i-- > 0)
		free(map[i]);
	return (0);
}

int	checkmap(int fd, char *header)
{
	int		i;
	int		lines;
	char	**map;
	char	*chars;

	i = 0;
	lines = chartoint(header);
	if (lines < 1)
		return (1);
	chars = (char *)malloc(3 * sizeof(char));
	while (header[i] != '\n')
		i++;
	chars[0] = header[i - 3];
	chars[1] = header[i - 2];
	chars[2] = header[i - 1];
	map = (char **)malloc(sizeof(char *) * lines);
	if (loadmap(fd, chars, map, lines))
	{
		free(chars);
		free(map);
		return (1);
	}
	free(chars);
	free(map);
	return (0);
}

int	checkheader(int fd, char *hdr, int i)
{
	int	j;

	i--;
	j = i - 2;
	if (hdr[i] == hdr[i - 1] || hdr[i] == hdr[j] || hdr[i - 1] == hdr[j])
		return (1);
	while (j-- > 0)
	{
		if (hdr[j] < '0' || hdr[j] > '9')
			return (1);
	}
	if (checkmap(fd, hdr))
		return (1);
	return (0);
}

int	readmap(int fd)
{
	int		i;
	char	*header;

	header = (char *)malloc(13 * sizeof(char));
	i = -1;
	while (i == -1 || (header[i] != '\n' && i < 13))
	{
		i++;
		read(fd, &header[i], 1);
	}
	if (i < 4 || checkheader(fd, header, i))
	{
		free(header);
		return (1);
	}
	free(header);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	if (argc == 1)
	{
		fd = 0;
		if (readmap(fd))
			write(1, "map error\n", 10);
	}
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1 || readmap(fd))
				write(1, "map error\n", 10);
			if (close(fd))
				return (1);
			i++;
		}
	}
	return (0);
}
