/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:43:41 by rnovotny          #+#    #+#             */
/*   Updated: 2022/11/03 13:44:25 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_itoa_print(int num)
{
	char	buf[10];
	int		i;

	if (num == -2147483648)
		write(1, "-2147483648", 11);
	if (num < 0 && num != -2147483648)
	{	
		num = -num;
		write(1, "-", 1);
	}
	if (num == 0)
		write(1, "0", 1);
	i = 0;
	while (num > 0)
	{
		buf[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	while (i-- > 0)
		write(1, &buf[i], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 & str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res *= neg;
	return (res);
}

void	calculate(char *num1, char *num2, char op)
{
	int	res;

	res = 0;
	if (op == '+')
		res = ft_atoi(num1) + ft_atoi(num2);
	if (op == '-')
		res = ft_atoi(num1) - ft_atoi(num2);
	if (op == '/')
		res = ft_atoi(num1) / ft_atoi(num2);
	if (op == '*')
		res = ft_atoi(num1) * ft_atoi(num2);
	if (op == '%')
		res = ft_atoi(num1) % ft_atoi(num2);
	ft_itoa_print(res);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '/'
	&& argv[2][0] != '*' && argv[2][0] != '%')
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		write (1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		write (1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	calculate(argv[1], argv[3], argv[2][0]);
	return (0);
}
