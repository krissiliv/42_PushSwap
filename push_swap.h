/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgober <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:47:55 by pgober            #+#    #+#             */
/*   Updated: 2023/11/05 11:51:57 by pgober           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct t_hstruct
{
	int		wct;
	int		j;
	int		k;
}	t_mystruct;

typedef struct s_stack
{
	struct s_stack	*next;
	void			*data;
}	t_stack;

// libft
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			**ft_split(char const *s, char c);
int				is_num(char str);
int				ft_atoi(const char *nptr, int *error);

// check input
size_t			ft_strlen(const char *s);
int				check_double(t_stack *head);
int				ft_atoi_checker(int res, int c, int sign);
int				is_numseq(char **argv);

// create or print list
t_stack			*create_linked_stack(char **argv, int *error);
void			prntstack(t_stack *head);
t_stack			*copy_stack(t_stack *stck);

// elementary operations
void			sab(t_stack **head, char ab, bool print);
void			pab(t_stack **head_from, t_stack **head_to, char ab, \
									bool print);
void			rab(t_stack **head, char ab, bool print);
void			rrab(t_stack **head, char ab, bool print);

// collective operations
void			ss(t_stack **head, t_stack **head2, bool print);
void			rr(t_stack **head, t_stack **head2, bool print);
void			rrr(t_stack **head, t_stack **head2, bool print);

// whole list checks
int				correct_list1(t_stack *list, int len);
int				list_len(t_stack *head);
int				ascending(t_stack *list);
int				descending1(t_stack *list);

// search operations
t_stack			*last_node(t_stack *head);
int				smaller_node_pos1(t_stack *head, int cur_data);
int				smallest_pos12(t_stack *head);
t_stack			*optimal_node_to_move2(t_stack **head2, t_stack *head);
int				nearst_npos2(t_stack *head, int cur_data);

//effective operations
int				rotation_decision1(t_stack **head, t_stack **head2, \
									char ab, bool print);
int				swap_decision1(t_stack **head, t_stack **head2, \
									char ab, bool print);

//small list algorithm
int				ascndng(t_stack *head, t_stack *other);
int				algorithm_for3(t_stack **head, char ab, bool print);
int				small_list_alg(t_stack **head, t_stack **head2, bool print);

// my first algorithm
int				insert_at_right_pos1(t_stack **head, t_stack **head2, \
									bool print);
int				my_1st_push_swap(t_stack **head, t_stack **head2, bool print);

// my second algorithm
int				insert_at_right_pos2(t_stack **head, t_stack **head2, \
									bool print);
int				my_2nd_push_swap(t_stack **head, t_stack **head2, bool print);

// my second algorithm utils
long long int	abs_value2(long long int i);
int				npos2(t_stack *list, t_stack *node);
t_stack			*node_from_pos2(t_stack *list, int nodepos);
int				min2(int num1, int num2);
int				final_rotation2(t_stack **head, bool print);

// push_swap
void			free_stack(t_stack **head);
void			push_swap(t_stack **head, t_stack **head2);

#endif
