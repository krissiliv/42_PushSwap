/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:44:15 by pgober            #+#    #+#             */
/*   Updated: 2023/09/17 17:52:50 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_bstct
{
	int	incr;
	int	bytes;
}	t_bytest;

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_printf_d_int(int nbr);

#endif
