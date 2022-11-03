/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:55:10 by rnovotny          #+#    #+#             */
/*   Updated: 2022/10/31 13:58:26 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_display(int fd)
{
	char	line[80];
	int		bytes;

	bytes = 80;
	while (bytes == 80)
	{
		bytes = read(fd, line, 80);
		write(1, line, bytes);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (1);
	}
	ft_display(fd);
	if (close(fd))
		return (1);
	return (0);
}
