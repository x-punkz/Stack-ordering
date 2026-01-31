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
	ps_list *temp;
    ps_list *last;
    ps_list *second_last;

    if (a == NULL || *a == NULL)
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
    if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rotrev_b(ps_list **b, int print)
{
	ps_list *temp;
    ps_list *last;
    ps_list *second_last;

    if (b == NULL || *b == NULL)
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
    if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rotrev_ab(ps_list **a, ps_list **b)
{
	rotrev_a (a, 0);
    rotrev_b (b, 0);
	ft_putstr_fd("rrr\n", 1);
}
