/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots_a_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:54:01 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/28 16:54:03 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rot_a(ps_list **a, int print)
{
	ps_list	*first;
	//ps_list	*last;
	ps_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	tmp = *a;
	*a = (*a)->next;
	while (first->next != NULL)
		first = first->next;
	tmp->next = NULL;
	first->next = tmp;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rot_b(ps_list **b, int print)
{
	ps_list	*first;
	//ps_list	*last;
	ps_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	tmp = *b;
	*b = (*b)->next;
	while (first->next != NULL)
		first = first->next;
	tmp->next = NULL;
	first->next = tmp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rot_ab(ps_list **a, ps_list **b)
{
	rot_a(a, 0);
	rot_b(b, 0);
	ft_putstr_fd("rr\n", 1);
}