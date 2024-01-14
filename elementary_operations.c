/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementary_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:28:33 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 10:32:16 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack **head, char ab, bool print)
{
	t_stack	*tmp;

	if (!(*head && (*head)->next))
		return ;
	tmp = (*head)->data;
	(*head)->data = ((*head)->next)->data;
	((*head)->next)->data = tmp;
	if (ab == 'a' && print == true)
		write(1, "sa\n", 3);
	else if (print == true)
		write(1, "sb\n", 3);
}

void	pab(t_stack **head_from, t_stack **head_to, char ab, bool print)
{
	t_stack	*new_node;
	t_stack	*new_head;

	if (!(*head_from))
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = malloc(sizeof(int));
	if (!(new_node->data))
		return (free(new_node));
	*((int *)(new_node->data)) = *((int *)((*head_from)->data));
	new_node->next = *head_to;
	*head_to = new_node;
	new_head = (*head_from)->next;
	free((*head_from)->data);
	free(*head_from);
	*head_from = new_head;
	if (ab == 'a' && print == true)
		write(1, "pa\n", 3);
	else if (print == true)
		write(1, "pb\n", 3);
}

void	rab(t_stack **head, char ab, bool print)
{
	t_stack	*new_head;
	t_stack	*old_head;

	old_head = *head;
	new_head = (*head)->next;
	while ((*head)->next)
		(*head) = (*head)->next;
	(*head)->next = old_head;
	old_head->next = NULL;
	*head = new_head;
	if (ab == 'a' && print == true)
		write(1, "ra\n", 3);
	else if (print == true)
		write(1, "rb\n", 3);
}

void	rrab(t_stack **head, char ab, bool print)
{
	t_stack	*old_head;
	t_stack	*tmp;

	old_head = *head;
	while (((*head)->next)->next)
		(*head) = (*head)->next;
	tmp = (*head)->next;
	(*head)->next = NULL;
	*head = tmp;
	(*head)->next = old_head;
	if (ab == 'a' && print == true)
		write(1, "rra\n", 4);
	else if (print == true)
		write(1, "rrb\n", 4);
}
