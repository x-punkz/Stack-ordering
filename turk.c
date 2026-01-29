/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:35:54 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/27 15:36:27 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	doble_rotate(ps_list *stack_a, ps_list *stack_b)
{
	ps_list		*aux_a;
	ps_list		*aux_b;

	aux_a = stack_a;
	aux_b = stack_b;
	while (aux_a->cost > 0 && aux_b->cost > 0)
    {
        rot_ab(stack_a, stack_b);
 		(aux_a->cost)--;
		(aux_b->cost)--;
	}
	while (aux_a->cost < 0 && aux_b->cost < 0)
	{
		rotrev_ab(&stack_a, &stack_b);
		(aux_a->cost)++;
		(aux_b->cost)++;
	}
}

void	single_rotate(ps_list *stack_a, ps_list *stack_b)
{
	ps_list		*aux_a;
	ps_list		*aux_b;

	aux_a = stack_a;
	aux_b = stack_b;
	while (aux_a->cost > 0)
	{
	   	rot_a(&stack_a, 1);
	   	aux_a->cost--;
	}
	while (aux_a->cost < 0)
	{
		rotrev_a(&stack_a, 1);
	    aux_a->cost++;
	}
	while (aux_b->cost > 0)
	{
	    rot_b(&stack_b, 1);
	    aux_b->cost--;
	}
	while (aux_b->cost < 0)
	{
		rotrev_b(&stack_b, 1);
		aux_b->cost++;
	}	
}

ps_list		*cheap_cost(ps_list *stack_b)
{
	ps_list		*min_cheap;
	ps_list		*aux;
	
	aux = stack_b;
	min_cheap = aux;
	while(aux)
	{
		total_cost_calculate(stack_b);
		if (min_cheap->total_cost > aux->total_cost)
			min_cheap = aux;
		aux = aux->next;
	}
	return (min_cheap);
}

void	choose_movs(ps_list *stack_a, ps_list *stack_b)
{
	ps_list		*cheapest;
	ps_list		*aux_a;
	ps_list		*aux_b;
	
	aux_a = stack_a;
	aux_b = stack_b;
	cheapest = cheap_cost(stack_b);
	//while (aux_b)
	//{
		doble_rotate(aux_a, aux_b);
		single_rotate(aux_a, aux_b);
		push_a(stack_a, stack_b);
		// if (cheapest->index < ps_lstlen(stack_b)/ 2)
		// rot_b(stack_b, 1);
		// else if (cheapest->index == 0)
		// push_a(stack_a, stack_b);
		// else
		// rotrev_b(stack_b);
		// stack_b = stack_b->next;
	//}
}

void	turk(ps_list *stack_a, ps_list *stack_b)
{
	int		size;

	size = ps_lstlen(stack_a);
	move_b(&stack_a, &stack_b, size);
	update_index(stack_a);
	update_index(stack_b);
	sort_three(&stack_a);
	while (stack_b)
	{
		target(&stack_a, &stack_b);
		cost_calculate(stack_a, stack_b);
		choose_movs(stack_a, stack_b);
	}
	//fazer uma funçao p escolher os movimentos
	// se o cheap estiver da metdae p cima de b, rot_b
	// senao, rot_b
	
}
