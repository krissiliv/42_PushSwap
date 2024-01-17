/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collective_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:16:35 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 10:17:34 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **head, t_stack **head2, bool print) // swap the first two elements at the top of stack a and b
{
	sab(head, 'a', false);
	sab(head2, 'b', false);
	if (print == 1)
		write(1, "ss\n", 3);
}

void	rr(t_stack **head, t_stack **head2, bool print) // rotate stack a and b
{
	rab(head, 'a', false);
	rab(head2, 'b', false);
	if (print == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **head, t_stack **head2, bool print) // reverse rotate stack a and b
{
	rrab(head, 'a', false);
	rrab(head2, 'b', false);
	if (print == true)
		write(1, "rrr\n", 4);
}
