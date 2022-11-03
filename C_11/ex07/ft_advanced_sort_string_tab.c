/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:58:48 by rnovotny          #+#    #+#             */
/*   Updated: 2022/11/03 18:01:40 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*ptr;

	i = 1;
	while (tab[i])
	{
		if (cmp(tab[i - 1], tab[i]) > 0)
		{
			ptr = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = ptr;
		}
		i++;
	}
	i = 1;
	while (tab[i])
	{
		if (cmp(tab[i - 1], tab[i]) > 0)
			ft_advanced_sort_string_tab(tab);
		i++;
	}
}
