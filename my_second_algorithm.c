/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_second_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:52:01 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:12:23 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	alg1(t_stack **node, t_stack **list, int insert_pos, bool print) // algorithm 1 uses reverse rotate
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < list_len(*list) - insert_pos)
	{
		rrab(list, 'a', print);
		i++;
		j++;
	}
	pab(node, list, 'a', print);
	i++;
	return (i);
}

static int	alg2(t_stack **node, t_stack **list, int insert_pos, bool print) // algorithm 2 uses rotate. this is distinguished from algorithm 1 for optimization
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < insert_pos)
	{
		rab(list, 'a', print);
		i++;
		j++;
	}
	pab(node, list, 'a', print);
	i++;
	return (i);
}

int	insert_at_right_pos2(t_stack **node, t_stack **list, bool print)
{
	int	insert_pos;
	int	i;

	i = 0;
	insert_pos = nearst_npos2(*list, *(int *)(*node)->data);
	if (list_len(*list) - insert_pos <= insert_pos - 0) // choose the algorithm that takes the least number of operations
		return (i + alg1(node, list, insert_pos, print));
	return (i + alg2(node, list, insert_pos, print));
}

static int	push_back_to_head(t_stack **head, t_stack **head2, bool print)
{
	int	i;
	int	optimal_node_pos;

	i = 0;
	while (*head2)
	{
		optimal_node_pos = \
			npos2(*head2, optimal_node_to_move2(head2, *head)); // find the optimal node to move and its position
		if (list_len(*head2) - optimal_node_pos <= optimal_node_pos - 0)
		{
			i += list_len(*head2) - optimal_node_pos;
			while (0 < list_len(*head2) - optimal_node_pos++)
				rrab(head2, 'b', print);
		}
		else
		{
			i += optimal_node_pos;
			while (optimal_node_pos--)
				rab(head2, 'b', print);
		}
		i += insert_at_right_pos2(head2, head, print);
	}
	return (i);
}

int	my_2nd_push_swap(t_stack **head, t_stack **head2, bool print)
{
	int	i;

	i = 0;
	while (list_len(*head) > 3)
	{
		pab(head, head2, 'b', print);
		i++;
	}
	if (list_len(*head) == 3)
		i += algorithm_for3(head, 'a', print);
	i += push_back_to_head(head, head2, print);
	i += final_rotation2(head, print);
	return (i);
}
