/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:26:26 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/24 19:23:55 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*range;
	unsigned int	i;

	if (min < max)
		range = (int *) malloc(sizeof(int) * (max - min));
	else
		range = (int *) 0;
	i = 0;
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
