/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:07 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/22 14:11:28 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	special_cases(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb == 0)
		write(1, "0", 1);
}

void	ft_putnbr(int nb)
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
