/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:34 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/24 19:27:49 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	concat(char *dest, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
}

void	allocating(char *res, char **strs, char *sep, int l)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < l)
	{
		concat(&res[i], strs[k]);
		i += strl(strs[k]);
		if (i < l - strl(sep) || (i == l - strl(sep) && *strs[k] == 0))
		{
			concat(&res[i], sep);
			i += strl(sep);
		}
		k++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		l;
	char	*res;

	i = 0;
	l = 0;
	if (size <= 0)
	{
		res = (char *) malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	while (i < size)
	{
		l += strl(strs[i]);
		if (i < size - 1)
			l += strl(sep);
		i++;
	}
	res = (char *) malloc((l + 1) * sizeof(char));
	res[l] = '\0';
	allocating(res, strs, sep, l);
	return (res);
}
