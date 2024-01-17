/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_second_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:14:13 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:16:54 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	abs_value2(long long int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int	npos2(t_stack *list, t_stack *node) // check the position of the node in the list
{
	int	i;

	i = 0;
	while (list && list != node)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_stack	*node_from_pos2(t_stack *list, int nodepos)
{
	while (nodepos--)
		list = list->next;
	return (list);
}

int	min2(int num1, int num2)
{
	if (num1 <= num2)
		return (num1);
	return (num2);
}

int	final_rotation2(t_stack **head, bool print)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (j != 0 && list_len(*head) - smallest_pos12(*head) \
					<= smallest_pos12(*head) - 0)
	{
		while (j++ < list_len(*head) - smallest_pos12(*head))
		{
			rab(head, 'a', print);
			i++;
		}
	}
	else
	{
		while (j++ < smallest_pos12(*head))
		{
			rrab(head, 'a', print);
			i++;
		}
	}
	return (i);
}
