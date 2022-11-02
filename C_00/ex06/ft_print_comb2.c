/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:33:37 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/16 17:06:11 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			temp = i / 10 + 48;
			write(1, &temp, 1);
			temp = i % 10 + 48;
			write(1, &temp, 1);
			write(1, " ", 1);
			temp = j / 10 + 48;
			write(1, &temp, 1);
			temp = j % 10 + 48;
			write(1, &temp, 1);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
