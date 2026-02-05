/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:54:01 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/28 16:54:03 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rot_a(t_push **a)
{
	t_push	*first;
	t_push	*tmp;

	if (!*a || !(*a)->next)
		return ;
	if (ps_lstlen(*a) < 2)
		return ;
	first = *a;
	tmp = *a;
	*a = (*a)->next;
	while (first->next != NULL)
		first = first->next;
	tmp->next = NULL;
	first->next = tmp;
}

void	rot_b(t_push **b)
{
	t_push	*first;
	t_push	*tmp;

	if (!*b || !(*b)->next)
		return ;
	if (ps_lstlen(*b) < 2)
		return ;
	first = *b;
	tmp = *b;
	*b = (*b)->next;
	while (first->next != NULL)
		first = first->next;
	tmp->next = NULL;
	first->next = tmp;
}

void	rot_ab(t_push **a, t_push **b)
{
	if (ps_lstlen(*a) < 2)
		return ;
	if (ps_lstlen(*b) < 2)
		return ;
	rot_a(a);
	rot_b(b);
}

void	swap_ss(t_push **a, t_push **b)
{
	if (ps_lstlen(*a) < 2)
		return ;
	if (ps_lstlen(*b) < 2)
		return ;
	swap_a(a);
	swap_b(b);
}
