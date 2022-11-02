/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:52:14 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/22 14:08:41 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] != 0)
			{
				if (str[i] != to_find[j])
					break ;
				i++;
				j++;
			}
			if (to_find[j] == 0)
				return (&str[i - j]);
		}
		i++;
	}
	return (0);
}
