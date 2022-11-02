/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:47:34 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/24 19:29:38 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*strdup;

	i = 0;
	while (str[i] != '\0')
		i++;
	strdup = (char *) malloc(i + 1);
	if (strdup == 0)
		return (0);
	while (i >= 0)
	{
		strdup[i] = str[i];
		i--;
	}
	return (strdup);
}
