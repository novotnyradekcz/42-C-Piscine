/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:01:23 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/16 15:38:20 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "Invalid input. Enter only positive integers.", 44);
	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((i == 1 || i == y) && j == 1)
				ft_putchar('A');
			else if ((i == 1 || i == y) && j == x)
				ft_putchar('C');
			else if (i == 1 || i == y || j == 1 || j == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		if (x > 0 && y > 0)
			ft_putchar('\n');
		i++;
	}
}
