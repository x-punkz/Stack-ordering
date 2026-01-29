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
typedef struct push_list
{
	int			index;
	int			content;
	int			cost;
	int			total_cost;

	struct push_list	*target;
	struct push_list	*next;
	struct push_list	*prev;
}					ps_list;

void	print_stack(ps_list *stack);//apagar esta funçao
void	sort_stack(ps_list **a, ps_list **b);
int		ps_lstlen(ps_list *lst);
void    swap_a(ps_list *a);
void    swap_b(ps_list *b);
void    swap_ss(ps_list *a, ps_list *b);
void    rot_a(ps_list **a, int print);
void    rot_b(ps_list **b, int i);
void    rot_ab(ps_list *a, ps_list *b);
void    rotrev_a(ps_list **a, int print);
void    rotrev_b(ps_list **b, int print);
void    rotrev_ab(ps_list **a, ps_list **b);
void	lstswap(ps_list *stack);
void	sort_three(ps_list **stack_a);
void	sort_four(ps_list *stack_a, ps_list *stack_b);
ps_list		*min_node(ps_list *stack);
void   push_a(ps_list *a, ps_list *b);
void   push_b(ps_list **a, ps_list **b);
void	move_b(ps_list **stack_a, ps_list **stack_b, int size);/**/
void	update_index(ps_list *stack);
void	target(ps_list **stack_a, ps_list **stack_b);
void	cost_calculate(ps_list *stack, ps_list *stack_b);
void	total_cost_calculate(ps_list *stack);
ps_list		*cheap_cost(ps_list *stack_b);
void	turk(ps_list *stack_a, ps_list *stack_b);
void	choose_movs(ps_list *stack_a, ps_list *stack_b);
ps_list	*ps_lstlast(ps_list *lst);
ps_list	*ps_lstnew(int content);
void	ps_lstadd_front(ps_list **lst, ps_list *new);
#endif
