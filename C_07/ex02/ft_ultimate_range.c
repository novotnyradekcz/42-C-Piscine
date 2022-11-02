/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:39:03 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/26 15:37:11 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	int				*ptr;

	if (min < max)
		ptr = (int *) malloc(sizeof(int) * (max - min));
	else
	{
		*range = (int *) 0;
		return (0);
	}
	if (!(ptr))
		return (-1);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	*range = ptr;
	return (i);
}
