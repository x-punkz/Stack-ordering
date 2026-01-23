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
/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/
void	sort_stack(t_list *a, t_list *b);
int		ft_lstlen(t_list *lst);
void    swap_a(t_list *a);
void    swap_b(t_list *b);
void    swap_ss(t_list *a, t_list *b);
void    rot_a(t_list *a);
void    rot_b(t_list *b);
void    rot_ab(t_list *a, t_list *b);
void    rotrev_a(t_list *a);
void    rotrev_b(t_list *b);
void    rotrev_ab(t_list *a, t_list *b);
void	lstswap(t_list *stack);
void	sort_four(t_list *stack_a, t_list *stack_b);
int		min_node(t_list *stack);
int		max_node(t_list *stack);
//void	sort_five(t_list *stack_a, t_list *stack_b);
void   push_a(t_list *a, t_list *b);
void   push_b(t_list **a, t_list **b);
#endif
