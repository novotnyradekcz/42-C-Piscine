/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:44:53 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/26 16:42:23 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: isn't detecting invalid input properly (returns 0 instead)

#include <stdlib.h>

int	invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base [j] != 0)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	to_decimal(char *nbr, char *base, int i)
{
	unsigned int	res;
	int				bas;
	int				not;
	int				j;

	res = 0;
	bas = 0;
	while (base [bas] != 0)
		bas++;
	not = is_in(base, nbr[i]);
	while (not)
	{
		j = 0;
		while (j < bas)
		{
			if (nbr[i] == base[j])
				res = res * bas + j;
			j++;
		}
		i++;
		not = is_in(base, nbr[i]);
	}
	return (res);
}

char	*from_decimal(unsigned int dec, char *base)
{
	int		i;
	int		l;
	int		bas;
	int		temp[33];
	char	*res;

	bas = 0;
	while (base[bas] != 0)
		bas++;
	i = 0;
	while (dec > 0 || (i == 0 && dec == 0))
	{
		temp[i] = dec % bas;
		dec /= bas;
		i++;
	}
	l = i - 1;
	res = (char *) malloc(33 * sizeof(char));
	while (i <= 2 * l + 1)
	{
		res[i - l - 1] = base[temp[2 * l + 1 - i]];
		i++;
	}
	res[i - l - 1] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		neg;
	int		dec;
	char	*res;

	i = 0;
	neg = 1;
	if (invalid_base(base_from) || invalid_base(base_to))
		return (0);
	while ((nbr[i] >= 9 & nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == 43 || nbr[i] == 45)
	{
		if (nbr[i] == 45)
			neg = -neg;
		i++;
	}
	dec = to_decimal(nbr, base_from, i);
	res = from_decimal(dec, base_to);
	if (neg == -1 && dec != 0)
	{
		res--;
		res[0] = '-';
	}
	return (res);
}
