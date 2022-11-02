/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:21:00 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:30 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l;

	i = 0;
	while (dest[i] != 0)
		i++;
	l = i;
	while (src[i - l] != 0)
	{
		dest[i] = src[i - l];
		i++;
	}
	dest[i] = 0;
	return (dest);
}