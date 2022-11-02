/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:45:07 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/18 14:44:01 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	while (dest[i] != 0)
		i++;
	l = i;
	while (src[i - l] != 0 && i - l < nb)
	{
		dest[i] = src[i - l];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
