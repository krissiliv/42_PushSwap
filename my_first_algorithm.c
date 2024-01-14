/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_first_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:40:26 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 10:48:40 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	alg1(t_stack **head, t_stack **head2, int insert_pos, bool print)
{
	int	i;
	int	j;

	i = 0;
	j = list_len(*head2) - insert_pos;
	while (j > 0)
	{
		rrab(head2, 'b', print);
		i++;
		j--;
	}
	pab(head, head2, 'b', print);
	i++;
	j = 0;
	while (j < list_len(*head2) - insert_pos)
	{
		rab(head2, 'b', print);
		i++;
		j++;
	}
	return (i);
}

static int	alg2(t_stack **head, t_stack **head2, int insert_pos, bool print)
{
	int	i;
	int	j;

	i = 0;
	j = insert_pos;
	while (j > 0)
	{
		rab(head2, 'b', print);
		i++;
		j--;
	}
	pab(head, head2, 'b', print);
	i++;
	j = 0;
	while (j < insert_pos)
	{
		rrab(head2, 'b', print);
		i++;
		j++;
	}
	return (i);
}

int	insert_at_right_pos1(t_stack **head, t_stack **head2, bool print)
{
	int	insert_pos;
	int	i;

	i = 0;
	if (!(*head2 && (*head2)->next))
	{
		pab(head, head2, 'b', print);
		i++;
		return (1);
	}
	insert_pos = smaller_node_pos1(*head2, *(int *)(*head)->data);
	if (list_len(*head2) - insert_pos <= insert_pos - 0)
		return (i + alg1(head, head2, insert_pos, print));
	return (i + alg2(head, head2, insert_pos, print));
}

static int	pab_if_corr(t_stack **head, t_stack **head2, bool print, int *i)
{
	int	brk;

	brk = 0;
	if (descending1(*head2) && ascending(*head))
	{
		while (*head2)
		{
			pab(head2, head, 'a', print);
			(*i)++;
		}
		brk = 1;
	}
	return (brk);
}

int	my_1st_push_swap(t_stack **head, t_stack **head2, bool print)
{
	int	lstlen;
	int	i;

	i = 0;
	lstlen = list_len(*head);
	while (correct_list1(*head, lstlen) == 0)
	{
		while (list_len(*head) > 3)
		{
			i += rotation_decision1(head, head2, 'a', print);
			i += swap_decision1(head, head2, 'a', print);
			if (pab_if_corr(head, head2, print, &i))
				break ;
			if (*head)
				i += insert_at_right_pos1(head, head2, print);
		}
		if (list_len(*head) == 3)
			i += algorithm_for3(head, 'a', print);
		while (*head2)
		{
			pab(head2, head, 'a', print);
			i++;
		}
	}
	return (i);
}
