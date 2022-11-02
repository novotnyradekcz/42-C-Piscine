/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:52:16 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/19 12:36:52 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	while (dest[i] != 0 && i < size)
		i++;
	l = i;
	while (src[i - l] != 0)
	{
		if (i < size - 1)
			dest[i] = src[i - l];
		if (i == size - 1)
			dest[i] = 0;
		i++;
	}
	return (i);
}
