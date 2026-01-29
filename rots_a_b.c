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
	ps_list	*last;

	if (!*a || !(*a)->next)
		return ;
	first = ps_lstnew((*a)->content);
	*a = (*a)->next;
		// 4. Encontra o último elemento da lista
	last = *a;
	while (last->next)
	{
		last = last->next;
		if (last->next == *a)
			break ;
	}
	
	// 5. Move o primeiro elemento para o final
	last->next = first;
	first->prev = last;
	(*a)->prev = first;
	first->next = NULL;
	

	/*ps_list	*tmp;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = a->prev->content;
	a->prev->content = tmp;*/
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rot_b(ps_list **b, int print)
{
	ps_list	*first;
	ps_list	*last;

	if (!*b || !(*b)->next)
		return ;
	first = ps_lstnew((*b)->content);
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	(*b)->prev = first;
	first->next = NULL;
	// ps_list	*tmp;

	// tmp = b->content;
	// b->content = b->next->content;
	// b->next->content = b->prev->content;
	// b->prev->content = tmp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rot_ab(ps_list *a, ps_list *b)
{
	rot_a(&a, 0);
	rot_b(&b, 0);
	ft_putstr_fd("rr\n", 1);
}