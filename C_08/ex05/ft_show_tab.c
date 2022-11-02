/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:36:36 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/31 10:32:04 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	special_cases(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb == 0)
		write(1, "0", 1);
}

void	printnbr(int nb)
{
	char	buf[10];
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	special_cases(nb);
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		neg = 1;
	}
	while (nb > 0)
	{
		buf[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	if (neg)
		write(1, "-", 1);
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
}

void	printstr(char *str)
{
	int	n;

	n = 0;
	while (str[n] != 0)
		n++;
	write(1, str, n);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		printstr(par[i].str);
		write(1, "\n", 1);
		printnbr(par[i].size);
		write(1, "\n", 1);
		printstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
