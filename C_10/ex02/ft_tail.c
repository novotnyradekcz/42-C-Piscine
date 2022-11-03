/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:22:10 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/31 14:22:55 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n] != 0)
		n++;
	write(1, str, n);
}

void	ft_display(int fd)
{
	char	line[30];
	int		bytes;

	bytes = 30;
	while (bytes == 30)
	{
		bytes = read(fd, line, 30);
		write(1, line, bytes);
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc || argc == 1)
	{
		if (argc == 1)
			fd = 0;
		else
			fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "cat: ", 5);
			ft_putstr(argv[i]);
			write(1, ": Permission denied\n", 20);
			return (1);
		}
		ft_display(fd);
		if (close(fd))
			return (1);
		i++;
	}
	return (0);
}