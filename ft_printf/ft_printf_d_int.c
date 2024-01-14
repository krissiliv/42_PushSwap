/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:37:50 by pgober            #+#    #+#             */
/*   Updated: 2023/09/14 18:15:30 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}

static int	numsize(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		while (nbr <= -10)
		{
			nbr /= 10;
			i++;
		}
		i++;
	}
	else
	{
		while (nbr >= 10)
		{
			nbr /= 10;
			i++;
		}
	}
	return (i);
}

int	ft_printf_d_int(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (numsize(nbr) * sizeof(char));
}
