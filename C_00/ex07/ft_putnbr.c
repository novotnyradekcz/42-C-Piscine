/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:51:07 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/16 14:41:51 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int				l;
	unsigned int	temp;
	char			buff[10];

	temp = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		temp = -nb;
	}
	l = 0;
	while (temp > 9)
	{
		buff[l] = temp % 10 + 48;
		temp /= 10;
		l++;
	}
	buff[l] = temp + 48;
	while (l >= 0)
	{
		write(1, &buff[l], 1);
		l--;
	}
}
