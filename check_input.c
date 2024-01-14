/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:10:55 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 10:16:08 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	check_double(t_stack *head)
{
	t_stack	*curr1;
	t_stack	*curr2;

	curr1 = head;
	while (curr1)
	{
		curr2 = curr1->next;
		if (!curr2)
			break ;
		while (curr2)
		{
			if (*((int *)(curr2->data)) == *((int *)(curr1->data)))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
		if (!curr1)
			break ;
	}
	return (0);
}

int	ft_atoi_checker(int res, int c, int sign)
{
	if (sign > 0 && res > (2147483647 - (c - '0')) / 10)
		return (0);
	if (sign < 0 && -(res) < (-2147483648 + (c - '0')) / 10)
		return (0);
	return (1);
}

int	is_numseq(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && !is_num(argv[i][j + 1])) || \
				(argv[i][j] == '+' && !is_num(argv[i][j + 1])) || \
				(argv[i][j] != '-' && argv[i][j] != '+' && !is_num(argv[i][j])))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
