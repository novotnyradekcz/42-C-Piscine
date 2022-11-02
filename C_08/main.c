/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:22:03 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/31 10:25:54 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab.c"

int	main(int argc, char **argv)
{
	int	i;
	t_stock_str	*str;

	str = ft_strs_to_tab(argc, argv);
	for(i=0; i<argc + 1; i++)
	{
		printf("%s\n", str[i].str);
		printf("%d\n", str[i].size);
		printf("%s\n", str[i].copy);
	}
	ft_show_tab(str);
}
