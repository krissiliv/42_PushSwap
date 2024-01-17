/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:17:18 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:23:15 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	free_stack(t_stack **head)
{
	t_stack	*pos;

	pos = *head;
	while (pos != NULL)
	{
		free(pos->data);
		*head = pos;
		pos = pos->next;
		free(*head);
	}
}

void	push_swap(t_stack **head, t_stack **head2)
{
	t_stack	*hhead;
	t_stack	*hhead2;

	if (ascending(*head))
		return ;
	if (list_len(*head) <= 2)
	{
		if (ascending(*head))
			return ;
		sab(head, 'a', true);
		return ;
	}
	hhead = copy_stack(*head); // copy stack to use it for checking which algorithm is better
	hhead2 = NULL;
	if (!hhead)
		return (free_stack(&hhead), free_stack(&hhead2));
	if (list_len(*head) == 3 || list_len(*head) == 5)
		small_list_alg(head, head2, 1);
	else if (my_1st_push_swap(&hhead, &hhead2, 0) \
					< my_2nd_push_swap(&hhead, &hhead2, 0)) // compare the two sorting algorithms
		my_1st_push_swap(head, head2, 1);
	else
		my_2nd_push_swap(head, head2, 1);
	return (free_stack(&hhead), free_stack(&hhead2));
}

static int	executing_push_swap(int argc, char **argv, int *error)
{
	t_stack	*head;
	t_stack	*head2;

	head = create_linked_stack(argv, error);
	head2 = NULL;
	if (argc == 2)
		free_argv(argv);
	if (!head)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (*error)
	{
		write(2, "Error\n", 6);
		return (free_stack(&head), free_stack(&head2), 0);
	}
	if (check_double(head) == 1) // check that there are no duplicate numbers
		return (free_stack(&head), free_stack(&head2), 0);
	push_swap(&head, &head2);
	return (free_stack(&head), free_stack(&head2), 1);
}

int	main(int argc, char **argv)
{
	int	error;

	error = 0;
	if ((2 == argc && !argv[1][0]) || argc == 1)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv++;
	if (!argv || !is_numseq(argv))
	{
		if (argc == 2)
			free_argv(argv);
		return (0);
	}
	if (executing_push_swap(argc, argv, &error) == 0)
		return (0);
	return (0);
}
