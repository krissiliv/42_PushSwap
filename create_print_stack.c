/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_print_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:18:02 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 10:23:22 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(int data)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->data = malloc(sizeof(int));
	if (!(temp->data))
		return (free(temp), NULL);
	*((int *)(temp->data)) = data;
	temp->next = NULL;
	return (temp);
}

static void	initiate(t_stack **head, t_stack **temp, t_stack **pos)
{
	*head = NULL;
	*temp = NULL;
	*pos = NULL;
}

t_stack	*create_linked_stack(char **argv, int *error)
{
	int		i;
	t_stack	*head;
	t_stack	*temp;
	t_stack	*pos;

	if (!argv)
		return (NULL);
	initiate(&head, &temp, &pos);
	i = -1;
	while (argv[++i])
	{
		temp = create_node(ft_atoi(argv[i], error));
		if (temp == NULL)
			return (free_stack(&head), NULL);
		if (head == NULL)
			head = temp;
		else
		{
			pos = head;
			while (pos->next != NULL)
				pos = pos->next;
			pos->next = temp;
		}
	}
	return (head);
}

void	prntstack(t_stack *head)
{
	while (head)
	{
		ft_printf("%d", *((int *)(head->data)));
		if (head->next)
			ft_printf(" -> ");
		head = head->next;
	}
}

t_stack	*copy_stack(t_stack *stck)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*pos;

	if (!stck)
		return (NULL);
	initiate(&head, &temp, &pos);
	while (stck)
	{
		temp = create_node(*((int *)(stck->data)));
		if (temp == NULL)
			return (free_stack(&head), NULL);
		if (head == NULL)
			head = temp;
		else
		{
			pos = head;
			while (pos->next != NULL)
				pos = pos->next;
			pos->next = temp;
		}
		stck = stck->next;
	}
	return (head);
}
