/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_list_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:45:04 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:47:21 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_stack *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	correct_list1(t_stack *list, int len)
{
	if (list_len(list) != len)
		return (0);
	while (list->next)
	{
		if (*((int *)(list->next)->data) < *((int *)list->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int	descending1(t_stack *list)
{
	if (!list)
		return (-1);
	while (list->next)
	{
		if (*((int *)list->data) < *((int *)(list->next)->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int	ascending(t_stack *list)
{
	if (!list)
		return (-1);
	while (list->next)
	{
		if (*((int *)(list->next)->data) < *((int *)list->data))
			return (0);
		list = list->next;
	}
	return (1);
}
