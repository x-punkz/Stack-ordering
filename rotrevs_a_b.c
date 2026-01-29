/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotrevs_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:57:20 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/28 16:57:26 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft/libft.h"

void	rotrev_a(ps_list **a, int print)
{
	ps_list *last;
    ps_list *before_last;
    
    if (!*a || !(*a)->next)
        return ;
    before_last = *a;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *a;
    *a = last;
    if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rotrev_b(ps_list **b, int print)
{
	ps_list *last;
    ps_list *before_last;
    
    if (!*b || !(*b)->next)
        return;
    before_last = *b;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *b;
    *b = last;
    if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rotrev_ab(ps_list **a, ps_list **b)
{
	ps_list *last_a;
	ps_list *last_b;
    ps_list *before_last_a;
    ps_list *before_last_b;
    
    if (!*a || !(*a)->next)
        return;
    before_last_a = *a;
    while (before_last_a->next->next)
        before_last_a = before_last_a->next;
    last_a = before_last_a->next;
    before_last_a->next = NULL;
    last_a->next = *a;
    *a = last_a;
	if (!*b || !(*b)->next)
        return;
    before_last_b = *b;
    while (before_last_b->next->next)
        before_last_b = before_last_b->next;
    last_b = before_last_b->next;
    before_last_b->next = NULL;
    last_b->next = *b;
    *b = last_b;
	ft_putstr_fd("rrr\n", 1);
}
