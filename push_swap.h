/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:56:05 by daniviei          #+#    #+#             */
/*   Updated: 2025/12/23 18:05:56 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

typedef struct s_push
{
	int				content;
	struct s_push	*next;
	struct s_push	*target;
	int				index;
	int				total_cost;
	int				target_index;
	int				cost_a;
	int				cost_b;
	int				index_final;
	struct s_push	*prev;
}					t_push;

void	free_list(t_push **list);
void	free_matrix(char **str);
int		verify(char *arg);
int		check_double(char **matrix);
void	join(t_push **holder, char *buf);
void	append_lst(t_push **stack_a, char **matrix);
void	target_index(t_push *stack_a, t_push *stack_b);
void	index_final(t_push *stack);
int		is_sorted(t_push *stack);
void	sort_stack(t_push **a, t_push **b);
int		ps_lstlen(t_push *lst);
void	swap_a(t_push *a);
void	swap_b(t_push *b);
void	swap_ss(t_push *a, t_push *b);
void	rot_a(t_push **a, int print);
void	rot_b(t_push **b, int i);
void	rot_ab(t_push **a, t_push **b);
void	rotrev_a(t_push **a, int print);
void	rotrev_b(t_push **b, int print);
void	rotrev_ab(t_push **a, t_push **b);
void	lstswap(t_push *stack);
void	sort_three(t_push **stack_a);
void	sort_four(t_push *stack_a, t_push *stack_b);
t_push	*min_node(t_push *stack);
int		max_index(t_push *stack);
void	push_a(t_push **a, t_push **b);
void	push_b(t_push **a, t_push **b);
void	move_b(t_push **stack_a, t_push **stack_b, int size);
void	update_index(t_push *stack_a, t_push *stack_b);
void	target(t_push *stack_a, t_push *stack_b);
void	cost_calculate(t_push *stack, t_push *stack_b);
int		total_cost_calculate(t_push *stack_b);
t_push	*cheap_cost(t_push *stack_b);
void	turk(t_push **stack_a, t_push **stack_b);
void	choose_movs(t_push **stack_a, t_push **stack_b);
void	double_rotate(t_push **stack_a, t_push **stack_b, t_push *cheap);
void	single_rotate(t_push **stack_a, t_push **stack_b, t_push *cheap);
void	ps_lstadd_back(t_push **lst, t_push *new);
t_push	*ps_lstlast(t_push *lst);
t_push	*ps_lstnew(int content);
void	ps_lstadd_front(t_push **lst, t_push *new);
int		mod(int n);
char	*ps_strjoin(char **s1, char const *s2);
void	final_order(t_push **stack_a);
#endif
