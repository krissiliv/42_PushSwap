/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:24:03 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:29:59 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

int	smaller_node_pos1(t_stack *head, int cur_data) // check which node is the next that's value is bigger than the value of the current node
{
	int	i;

	i = 0;
	while (head && cur_data < *(int *)(head->data))
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	smallest_pos12(t_stack *head) // check which node's value is the smallest
{
	int		i;
	t_stack	*smallest;
	t_stack	*curr;

	i = 0;
	curr = head;
	smallest = curr;
	while (curr)
	{
		if (*(int *)(curr->data) < *(int *)(smallest->data))
			smallest = curr;
		i++;
		curr = curr->next;
	}
	i = 0;
	while (head != smallest)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	nearst_npos2(t_stack *head, int cur_data) // check which node's value has the smallest difference from the current node's value
{
	int					i;
	t_stack				*curr;
	t_stack				*nearest;

	curr = head;
	nearest = curr;
	while (curr)
	{
		if (abs_value2((long long int)(*(int *)(curr->data)) \
			- (long long int)cur_data) \
			< abs_value2((long long int)(*(int *)(nearest->data)) \
			- (long long int)cur_data))
			nearest = curr;
		curr = curr->next;
	}
	i = 0;
	while (head != nearest)
	{
		i++;
		head = head->next;
	}
	if (*(int *)(nearest->data) < cur_data)
		i++;
	return (i);
}

t_stack	*optimal_node_to_move2(t_stack **head2, t_stack *head) // optimization
{
	int		cost;
	int		ccst;
	t_stack	*curr2;
	t_stack	*best_node;
	t_stack	*nnode;

	ccst = 0;
	cost = -1;
	curr2 = *head2;
	best_node = curr2;
	while (curr2)
	{
		nnode = node_from_pos2(head, nearst_npos2(head, *((int *)curr2->data)));
		ccst = min2(list_len(head) - npos2(head, nnode), npos2(head, nnode)) \
		+ min2(list_len(*head2) - npos2(*head2, curr2), npos2(*head2, curr2));
		if (cost == -1 || cost > ccst)
		{
			best_node = curr2;
			cost = ccst;
		}
		if (list_len(curr2) == 1)
			break ;
		curr2 = curr2->next;
	}
	return (best_node);
}
