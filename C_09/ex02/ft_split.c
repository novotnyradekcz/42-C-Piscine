/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:28:22 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/25 20:31:20 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char *str, char c)
{
	int	i;

	if (c == '\0')
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!(is_sep(sep, str[i])) && is_sep(sep, str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

void	copy(char *dest, char *src, char *sep)
{
	int	i;

	i = 0;
	while (!(is_sep(sep, src[i])))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split(char **res, char *str, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (is_sep(sep, str[i]))
			i++;
		else
		{
			j = 0;
			while (!(is_sep(sep, str[i + j])))
				j++;
			res[k] = (char *)malloc(sizeof(char) * (j + 1));
			copy(res[k], &str[i], sep);
			i += j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		size;

	size = count(str, charset);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	res[size] = 0;
	split(res, str, charset);
	return (res);
}
