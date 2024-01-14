/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:43:06 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:44:52 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascndng(t_stack *head, t_stack *other)
{
	if (*((int *)head->data) < *((int *)other->data))
		return (1);
	return (0);
}

int	algorithm_for3(t_stack **head, char ab, bool print)
{
	int	i;

	i = 0;
	if (ascndng((*head)->next, *head) && ascndng(last_node(*head), *head))
	{
		rab(head, ab, print);
		i++;
	}
	else if (ascndng(*head, (*head)->next) \
					&& ascndng(last_node(*head), (*head)->next))
	{
		rrab(head, ab, print);
		i++;
	}
	if (ascndng((*head)->next, *head))
	{
		sab(head, ab, print);
		i++;
	}
	return (i);
}

int	small_list_alg(t_stack **head, t_stack **head2, bool print)
{
	int	i;
	int	len;

	i = 0;
	i += rotation_decision1(head, head2, 'a', print);
	if (ascending(*head))
		return (i);
	len = list_len(*head);
	if (len == 5)
	{
		swap_decision1(head, head2, 'a', print);
		pab(head, head2, 'b', print);
		swap_decision1(head, head2, 'a', print);
		pab(head, head2, 'b', print);
		i += 2;
	}
	i += algorithm_for3(head, 'a', print);
	if (len == 5)
	{
		while (list_len(*head2) != 0)
			i += insert_at_right_pos2(head2, head, print);
		final_rotation2(head, print);
	}
	return (i);
}
