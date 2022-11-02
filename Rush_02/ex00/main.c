/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:26:06 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/28 22:29:39 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	decompose1(char *str, char *dict);

int	checknbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '\0')
	{
		write(1, "Error", 5);
		return (1);
	}
	while (nbr[i] != '\0')
	{
		if (nbr[i] < '0' || nbr[i] > '9')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*findnbr(char *nbr, char *b)
{
	int		j;
	char	*ptr;

	while (*b != '\0')
	{
		j = 0;
		while (nbr[j] != '\0')
		{
			if (*b != nbr[j])
				break ;
			b++;
			j++;
		}
		if (nbr[j] == '\0')
		{
			if (*b >= '0' && *b <= '9' || *(b - j - 1) != '\n')
				continue ;
			ptr = &*(b - j);
			return (ptr);
		}
		b++;
	}
	return (0);
}

void	printnbr(char *d)
{
	int	i;

	i = 0;
	while ((d[i] >= '0' && d[i] <= '9'))
		i++;
	while ((d[i] > 8 && d[i] < 14) || d[i] == 32 || d[i] == ':')
		i++;
	while (d[i] != '\n')
	{		
		if (d[i] > ' ' && d[i] < 127)
			write(1, &d[i], 1);
		if ((d[i] > 8 && d[i] < 14) || d[i] == ' ')
		{
			if (d[i - 1] > 32 && d[i - 1] < 127)
				write(1, " ", 1);
		}
		i++;
	}
	write(1, " ", 1);
}

int	searchnbr(char *dict, char *nbr)
{
	char	*buf;
	char	*dentry;
	int		fd;
	int		dsize;

	fd = open(dict, O_RDONLY);
	buf = malloc(81920);
	dsize = read(fd, buf, 81920);
	if (dsize == 0)
	{
		write(1, "Dict error", 10);
		free(buf);
		return (1);
	}
	dentry = findnbr(nbr, buf);
	if (dentry)
		printnbr(dentry);
	else
		write(1, "Dict error", 10);
	close(fd);
	free(buf);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*dict;
	int		fd;

	if (argc == 2)
	{
		nbr = argv[1];
		dict = "numbers.dict";
	}
	else if (argc == 3)
	{
		nbr = argv[2];
		dict = argv[1];
	}
	else
	{
		write(1, "Error", 5);
		return (1);
	}
	if (checknbr(nbr))
		return (1);
	decompose1(nbr, dict);
	write(1, "\n", 1);
	return (0);
}
