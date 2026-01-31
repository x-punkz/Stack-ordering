/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:35:53 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/27 14:35:54 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	move_b(ps_list **stack_a, ps_list **stack_b, int size)
{
	int 	i;

	i = 0;
	while (i < size / 2)
	{
		if ((*stack_a)->index_final < size / 2)//coloquei o =
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			rot_a(stack_a, 1);
	}
	while (ps_lstlen(*stack_a) > 3)
		push_b(stack_a, stack_b);
}

void	update_index(ps_list *stack_a, ps_list *stack_b)
{
	int	i;
	ps_list		*aux;
	ps_list		*aux_b;

	aux = stack_a;
	aux_b = stack_b;
	i = 0;

	while (aux)
	{
		aux->index = i;
		aux = aux->next;
		i++;
	}
	i = 0;

	while (aux_b)
	{
		aux_b->index = i;
		aux_b = aux_b->next;
		i++;
	}
}

void	target(ps_list *stack_a, ps_list *stack_b)
{
	int			i;
	ps_list		*aux_a;
	ps_list		*aux_b;
	int		maybe_target;
	ps_list	*target;
	
	i = 0;
	aux_b = stack_b;
	while (aux_b)
	{
		maybe_target = INT_MAX;
		target = NULL;
		aux_a = stack_a;
		while (aux_a)
		{
			if (aux_a->content > aux_b->content
				&& aux_a->content <= maybe_target)
			{
				maybe_target = aux_a->content;
				target = aux_a;
			}
			aux_a = aux_a->next;
		}
		if (!target)
			target = min_node(stack_a);
		aux_b->target = target;
		aux_b = aux_b->next;
	}
}

void	cost_calculate(ps_list *stack_a, ps_list *stack_b)
{
	int		len_a;
	int		len_b;

	len_a = ps_lstlen(stack_a);
	len_b = ps_lstlen(stack_b);
	while (stack_b)
	{
		if (stack_b->target_index <= len_a / 2)
			stack_b->cost_a = stack_b->target_index;
		else
			stack_b->cost_a = stack_b->target_index - len_a;
		if (stack_b->index <= len_b / 2)
			stack_b->cost_b = stack_b->index;
		else
			stack_b->cost_b = stack_b->index - len_b;
		stack_b = stack_b->next;
	}
}

int	total_cost_calculate(ps_list *stack_b)
{
	ps_list		*aux_b;
	int	cost_a;
	int	cost_b;

	aux_b = stack_b;
	cost_a = aux_b->cost_a;
	cost_b = aux_b->cost_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (mod(cost_a) >= mod(cost_b))
			aux_b->total_cost = mod(cost_a);
		else
			aux_b->total_cost = mod(cost_b);
	}
	else
		aux_b->total_cost = mod(cost_a) + mod(cost_b);
	return (aux_b->total_cost);
}
