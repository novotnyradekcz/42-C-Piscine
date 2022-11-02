/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:14:44 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/30 12:14:51 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char			*findnbr(char *nbr, char *buf);

void			printnbr(char *d);

int				searchnbr(char *dict, char *nbr);

char			*small(int nbr);

unsigned int	toint(char *str);

char			*tochar(unsigned int nbr);

void	decompose4(unsigned int nbr, char *dict)
{
	char	*ptr;

	if (nbr % 100 < 20 && nbr % 100 != 0)
	{
		ptr = tochar(nbr % 100);
		searchnbr(dict, ptr);
		free(ptr);
	}
	else
	{
		if (((nbr % 100) / 10) * 10)
		{
			ptr = tochar(((nbr % 100) / 10) * 10);
			searchnbr(dict, ptr);
			free(ptr);
		}
		if (nbr % 10 != 0)
		{
			ptr = tochar(nbr % 10);
			searchnbr(dict, ptr);
			free(ptr);
		}
	}
}

void	decompose3(unsigned int nbr, char *dict)
{
	char	*ptr;

	if (nbr / 100 != 0)
	{
		ptr = tochar(nbr / 100);
		searchnbr(dict, ptr);
		free(ptr);
		ptr = tochar(100);
		searchnbr(dict, ptr);
		free(ptr);
	}
	if (nbr < 20 && nbr != 0)
	{
		ptr = tochar(nbr);
		searchnbr(dict, tochar(nbr));
		free(ptr);
	}
	else
		decompose4(nbr, dict);
}

void	decompose2(unsigned int nbr, char *dict)
{
	char	*ptr;

	if (nbr / 1000000 != 0)
	{
		decompose2(nbr / 1000000, dict);
		ptr = tochar(1000000);
		searchnbr(dict, ptr);
		free(ptr);
		nbr %= 1000000;
	}
	if (nbr / 1000 != 0)
	{
		decompose2(nbr / 1000, dict);
		ptr = tochar(1000);
		searchnbr(dict, ptr);
		free(ptr);
		nbr %= 1000;
	}
	decompose3(nbr, dict);
}

void	decompose1(char *str, char *dict)
{
	unsigned int	nbr;
	char			*ptr;

	nbr = toint(str);
	if (nbr == 0 && str[0] == '0')
	{
		ptr = tochar(nbr);
		searchnbr(dict, ptr);
		free(ptr);
	}
	if (nbr == 0 && str[0] != '0')
		return ;
	if (nbr / 1000000000 != 0)
	{
		decompose2(nbr / 1000000000, dict);
		ptr = tochar(1000000000);
		searchnbr(dict, ptr);
		free(ptr);
		nbr %= 1000000000;
	}
	decompose2(nbr, dict);
}
