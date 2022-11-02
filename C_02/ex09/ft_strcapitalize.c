/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:39:42 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/18 12:36:03 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_not_alphanumeric(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	i = 0;
	while (str[i + 1] != 0)
	{
		if (str[i + 1] >= 65 && str[i + 1] <= 90)
			str[i + 1] += 32;
		if (str[i + 1] >= 97 && str[i + 1] <= 122)
		{
			if (is_not_alphanumeric(str[i]))
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
