/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:36:59 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/25 12:55:06 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strcomp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return (s1[i] - s2[i]);
}

void	printstr(char *str)
{
	int	n;

	n = 0;
	while (str[n] != 0)
		n++;
	write(1, str, n);
}

void	sort(int c, char **v)
{
	int	i;
	int	j;
	int	print;

	i = 1;
	while (i < c)
	{
		j = 1;
		print = 1;
		while (j < c)
		{
			if (strcomp(v[i % c], v[j]) > 0 && (v[j][0] != '\0'))
				print = 0;
			j++;
		}
		if (print && (v[i][0] != '\0'))
		{
			printstr(v[i]);
			write(1, "\n", 1);
			v[i][0] = '\0';
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		sort(argc, argv);
		count++;
	}
	return (0);
}
