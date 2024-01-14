/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effective_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:23:42 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 10:28:15 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_decision1(t_stack **head, t_stack **head2, char ab, bool print)
{
	int	i;

	i = 0;
	while (*head && ascndng(last_node(*head), *head))
	{
		if (*head2 && ascndng(*head2, last_node(*head2)))
		{
			rr(head, head2, print);
			i++;
		}
		else if (list_len(*head) - smallest_pos12(*head) \
						<= smallest_pos12(*head))
		{
			rrab(head, ab, print);
			i++;
		}
		else
		{
			rab(head, ab, print);
			i++;
		}
	}
	return (i);
}

int	swap_decision1(t_stack **head, t_stack **head2, char ab, bool print)
{
	int	i;

	i = 0;
	if ((*head)->next && ascndng((*head)->next, *head) && ab == 'a')
	{
		if (*head2 && (*head2)->next && ascndng(*head2, (*head2)->next))
			ss(head, head2, print);
		else
			sab(head, ab, print);
		i++;
	}
	if (*head2 && (*head2)->next && ascndng(*head2, (*head2)->next) \
					&& ab == 'b')
	{
		if ((*head)->next && ascndng((*head)->next, *head))
			ss(head, head2, print);
		else
			sab(head, ab, print);
		i++;
	}
	return (i);
}
