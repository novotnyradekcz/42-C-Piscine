/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:22:53 by dstarov           #+#    #+#             */
/*   Updated: 2022/11/02 17:25:58 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	draw(char **matrix, int *result, char *chars);

int		*findmax(int **f, int h, int w);

int		minim(int x, int y, int z);

void	transform(int **f, int h, int w);

int		**matrix(char **matrix, char *chars, int h, int w);

int	getwidth(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\n')
		j++;
	return (j);
}

int	chartoint(char *lines)
{
	int	i;
	int	e;
	int	res;

	i = 0;
	while (lines[i] != '\n')
		i++;
	i -= 3;
	res = 0;
	e = 1;
	while (i-- > 0)
	{
		res += (lines[i] - '0') * e;
		e *= 10;
	}
	return (res);
}

int	checklines(char **map, int lines, char *chars)
{
	int	i;
	int	j;
	int	width;

	width = 0;
	i = 0;
	while (i < lines)
	{
		j = 0;
		if (!(map[i]))
			return (1);
		while (map[i][j] != '\n')
		{
			if (map[i][j] != chars[0] && map[i][j] != chars[1])
				return (1);
			j++;
		}
		if (i == 0)
			width = j;
		if (j != width)
			return (1);
		i++;
	}
	return (0);
}

void	printresult(char **map, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	solve(char **map, int height, char *chars)
{
	int	i;
	int	width;
	int	**field;
	int	*result;

	width = getwidth(map);
	field = matrix(map, chars, height, width);
	transform(field, height, width);
	result = findmax(field, height, width);
	draw(map, result, chars);
	i = -1;
	while (++i < height)
		free(field[i]);
	free(field);
	free(result);
	printresult(map, height, width);
}
