/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:30:17 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/30 23:30:22 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*small(int nbr)
{
	char	*res;

	res = malloc(2);
	res[0] = nbr + '0';
	res[1] = '\0';
	return (res);
}

unsigned int	toint(char *str)
{
	int				i;
	unsigned int	res;

	res = 0;
	i = 0;
	while ((str[i] >= 9 & str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (res > (4294967295 - str[i] + '0') / 10)
		{
			write(1, "Error", 5);
			return (0);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*tochar(unsigned int nbr)
{
	char	buf[10];
	char	*res;
	int		i;
	int		l;

	i = 0;
	if (nbr < 10)
		return (small(nbr));
	while (nbr > 0)
	{
		buf[i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
	}
	l = i;
	res = malloc(l + 1);
	res[l] = '\0';
	i--;
	while (i >= 0)
	{
		res[l - i - 1] = buf[i];
		res[i] = buf[l - i - 1];
		i--;
	}
	return (res);
}
