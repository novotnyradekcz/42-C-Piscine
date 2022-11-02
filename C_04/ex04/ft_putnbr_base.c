/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:51:40 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/23 15:41:18 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	invalid_arg(char *base)
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

unsigned int	negatives(int nbr)
{
	unsigned int	new_nbr;

	new_nbr = nbr;
	if (nbr < 0)
		new_nbr = -nbr;
	return (new_nbr);
}

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	print(int nbr, char *base, char *str)
{
	int	i;

	if (nbr < 0)
		write(1, "-", 1);
	i = 0;
	if (nbr == 0)
		write(1, base, 1);
	else
	{
		while (str[i] != 0)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	unsigned int	l;
	int				buf[16];
	char			res[32];
	int				bas;

	if (invalid_arg(base))
		return ;
	l = negatives(nbr);
	bas = base_len(base);
	i = 0;
	while (l > 0)
	{
		buf[i] = l % bas;
		l /= bas;
		i++;
	}
	l = i;
	res[l] = '\0';
	while (i > 0)
	{
		i--;
		res[l - i - 1] = base[buf[i]];
	}
	print(nbr, base, res);
}
