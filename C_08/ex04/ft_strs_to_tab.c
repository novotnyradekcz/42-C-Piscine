/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:30:54 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/31 10:28:12 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	strl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*copy(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (strl(str) + 1));
	if (!(res))
	{
		free(res);
		return (0);
	}
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(res))
	{
		free(res);
		return (0);
	}
	i = 0;
	while (i < ac)
	{
		res[i].size = strl(av[i]);
		res[i].str = copy(av[i]);
		res[i].copy = copy(av[i]);
		i++;
	}
	res[ac].size = 0;
	res[ac].str = 0;
	res[ac].copy = 0;
	return (res);
}
