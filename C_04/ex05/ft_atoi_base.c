/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:56:19 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/23 20:01:27 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base [j] != 0)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	base_l(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	convert(char *str, char *base, int i)
{
	int	res;
	int	bas;
	int	not;
	int	j;

	res = 0;
	bas = base_l(base);
	not = is_in(base, str[i]);
	while (not)
	{
		j = 0;
		while (j < bas)
		{
			if (str[i] == base[j])
				res = res * bas + j;
			j++;
		}
		i++;
		not = is_in(base, str[i]);
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	neg;

	if (invalid_base(base))
		return (0);
	neg = 1;
	i = 0;
	while ((str[i] >= 9 & str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = -neg;
		i++;
	}
	res = convert(str, base, i);
	res *= neg;
	return (res);
}
