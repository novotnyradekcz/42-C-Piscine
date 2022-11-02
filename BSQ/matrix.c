/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:32:05 by dstarov           #+#    #+#             */
/*   Updated: 2022/11/02 18:36:28 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	draw(char **matrix, int *result, char *chars)
{
	int	i;
	int	j;

	i = result[0];
	while (i > result[0] - result[2])
	{
		j = result[1];
		while (j > result[1] - result[2])
		{
			matrix[i][j] = chars[2];
			j--;
		}
		i--;
	}
}

int	*findmax(int **f, int h, int w)
{
	int	i;
	int	j;
	int	*result;

	result = (int *)malloc(sizeof(int) * 3);
	result[2] = 0;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (f[i][j] > result[2])
			{
				result[0] = i;
				result[1] = j;
				result[2] = f[i][j];
			}
			j++;
		}
		i++;
	}
	return (result);
}

int	minim(int x, int y, int z)
{
	if (x <= y && x <= z)
		return (x);
	else if (y <= x && y <= z)
		return (y);
	else
		return (z);
}

void	transform(int **f, int h, int w)
{
	int	i;
	int	j;

	i = 1;
	while (i < h)
	{
		j = 1;
		while (j < w)
		{
			if (f[i][j] == 1)
				f[i][j] += minim(f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]);
			if (f[i][j] == 0)
				f[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**matrix(char **matrix, char *chars, int h, int w)
{
	int	i;
	int	j;
	int	**field;

	field = (int **)malloc(sizeof(int *) * h);
	i = 0;
	while (i < h)
	{
		field[i] = (int *)malloc(sizeof(int) * w);
		j = 0;
		while (j < w)
		{
			if (matrix[i][j] == chars[1])
				field[i][j] = 0;
			if (matrix[i][j] == chars[0])
				field[i][j] = 1;
			j++;
		}
		i++;
	}
	return (field);
}
