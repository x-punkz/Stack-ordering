/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:19:49 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/20 18:19:51 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlen(t_list *lst)
{
	int	count;

	count = 1;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

#include <stdio.h>

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
// 2 1 0 quebra
	a = stack_a;
	(void)stack_b;
	if (!stack_a)
		return ;
	if ((*(int *)a->content > *(int *)a->next->content) &&
		(*(int *)a->content > *(int *)a->prev->content))
		rot_a(a);
	if (*(int *)a->next->content > *(int *)a->prev->content)
		rotrev_a(a);
	else if (*(int *)a->content > *(int *)a->prev->content)
		rot_a(a);
	if (*(int *)a->content > *(int *)a->next->content)
		swap_a(a);
}
