/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:42:27 by rnovotny          #+#    #+#             */
/*   Updated: 2022/11/03 17:45:09 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*ptr;

	i = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
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
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			ft_sort_string_tab(tab);
		i++;
	}
}
