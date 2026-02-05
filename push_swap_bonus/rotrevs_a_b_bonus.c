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
#include "push_swap_bonus.h"

void	rotrev_a(t_push **a)
{
	t_push	*temp;
	t_push	*last;
	t_push	*second_last;

	if (a == NULL || *a == NULL)
		return ;
	if (ps_lstlen(*a) < 2)
		return ;
	temp = *a;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	last = temp;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rotrev_b(t_push **b)
{
	t_push	*temp;
	t_push	*last;
	t_push	*second_last;

	if (b == NULL || *b == NULL)
		return ;
	if (ps_lstlen(*b) < 2)
		return ;
	temp = *b;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	last = temp;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
}

void	rotrev_ab(t_push **a, t_push **b)
{
	if (ps_lstlen(*a) < 2)
		return ;
	if (ps_lstlen(*b) < 2)
		return ;
	rotrev_a(a);
	rotrev_b(b);
}
