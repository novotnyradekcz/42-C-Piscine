/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:33:42 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/17 11:07:59 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 1;
	while (i < size)
	{
		if (tab[i - 1] > tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = temp;
		}
		i++;
	}
	i = 1;
	while (i < size)
	{
		if (tab[i - 1] > tab[i])
			ft_sort_int_tab(tab, size);
		i++;
	}
}
