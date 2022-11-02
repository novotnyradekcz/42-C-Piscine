/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:01:23 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/16 15:30:03 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if (i == 1 && j == 1)
				ft_putchar('/');
			else if ((i == y && j == 1) || (i == 1 && j == x))
				ft_putchar('\\');
			else if (i == y && j == x)
				ft_putchar('/');
			else if (i == 1 || i == y || j == 1 || j == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			j++;
		}
		if (x > 0 && y > 0)
			ft_putchar('\n');
		i++;
	}
}
