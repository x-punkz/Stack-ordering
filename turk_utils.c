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
	int pushed;
	int chunk_size;
    
	pushed = 0;
	if (size <= 100)
		chunk_size = 20;
	else if (size <= 500)
		chunk_size = 45;
	else
		chunk_size = size / 11;
	while (size > 3 && pushed < size - 3)
	{
		if ((*stack_a)->index <= pushed)
		{
			push_b(stack_a, stack_b);
			if (ps_lstlen(*stack_b) > 1)
				rot_b(stack_b, 1);
			pushed++;
		}
		else if ((*stack_a)->index <= pushed + chunk_size)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rot_a(stack_a, 1);
	}
}

void	update_index(ps_list *stack)
{
	int	i;
	ps_list		*aux;

	aux = stack;
	i = 0;

	while (aux)
	{
		aux->index = i;
		aux = aux->next;
		i++;
	}
}

void	target(ps_list **stack_a, ps_list **stack_b)
{
	int			i;
	ps_list		*aux_a;
	ps_list		*aux_b;
	ps_list		*maybe_target;
	
	i = 0;
	aux_b = *stack_b;
	maybe_target = min_node(*stack_a);
	while (aux_b)
	{
		aux_a = *stack_a;
		while (aux_a)
		{
			if (aux_a->content > aux_b->content
				&& aux_a->content <= maybe_target->content)
				maybe_target = aux_a;
			aux_a = aux_a->next;
		}
		aux_b->target = maybe_target;
		aux_b = aux_b->next;
	}
}

void	cost_calculate(ps_list *stack_a, ps_list *stack_b)
{
	int	len;

	len = ps_lstlen(stack_a);
	while (stack_a)
	{
		if (stack_a->index > len / 2)
			stack_a->cost = stack_a->index;
		else
			stack_a->cost = len - stack_a->index;
		stack_a = stack_a->next;
	}
	len = ps_lstlen(stack_b);
	while (stack_b)
	{
		if (stack_b->index > len / 2)
			stack_b->cost = stack_b->index;
		else
			stack_b->cost = len - stack_b->index;
		stack_b = stack_b->next;
	}
}

void	total_cost_calculate(ps_list *stack)
{
	ps_list		*aux;

	aux = stack;
	while (aux)
	{
		aux->total_cost = aux->cost + aux->target->cost;
		aux = aux->next;
	}
}
