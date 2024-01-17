/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:15:28 by pgober            #+#    #+#             */
/*   Updated: 2023/09/15 21:56:40 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	choose_function(const char *format, int i, va_list args)
{
	char			formvar;

	formvar = *(format + i);
	if (formvar == 'i' || formvar == 'd')
		return (ft_printf_d_int((int)va_arg(args, int)));
	if (formvar != '\0')
		return (write(1, &formvar, 1), 1);
	return (0);
}

static void	format_adapter(const char *format, t_bytest *st)
{
	while (format[st->incr] != '\0')
	{
		if (format[st->incr] == '%' && format[st->incr + 1] == '%')
		{
			while (format[st->incr] == '%' && format[st->incr + 1] == '%')
			{
				ft_putchar_fd(format[st->incr + 1], 1);
				st->bytes += sizeof(char);
				st->incr += 2;
			}
		}
		else if (format[st->incr] == '%' && format[st->incr + 1] != '%')
			return ;
		else
		{
			ft_putchar_fd(format[st->incr++], 1);
			st->bytes += sizeof(char);
		}
	}
	return ;
}

int	ft_printf(const char *format, ...)
{
	t_bytest	*st;
	va_list		args;
	int			b;

	st = (t_bytest *)malloc(sizeof(t_bytest));
	if (!st || !format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (*format == '\0')
		return (0);
	va_start(args, format);
	st->incr = 0;
	st->bytes = 0;
	while (format[st->incr] != '\0')
	{
		format_adapter(format, st);
		if (format[st->incr] == '\0')
			break ;
		if (format[st->incr] == '%' && format[++(st->incr)] != '%')
			st->bytes += choose_function(format, st->incr, args);
		if (format[st->incr++] == '\0')
			break ;
	}
	va_end(args);
	b = st->bytes;
	return (free(st), b);
}
