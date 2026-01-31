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

void	double_rotate(ps_list **stack_a, ps_list **stack_b, ps_list *cheap)
{
	while (cheap->cost_a > 0 && cheap->cost_b > 0)
    {
        rot_ab(stack_a, stack_b);
 		(cheap->cost_a)--;
		(cheap->cost_b)--;
	}
	while (cheap->cost_a < 0 && cheap->cost_b < 0)
	{
		rotrev_ab(stack_a, stack_b);
		(cheap->cost_a)++;
		(cheap->cost_b)++;
	}
}

void	single_rotate(ps_list **stack_a, ps_list **stack_b, ps_list *cheap)
{
	while (cheap->cost_a > 0)
	{
	   	rot_a(stack_a, 1);
	   	cheap->cost_a--;
	}
	while (cheap->cost_a < 0)
	{
		rotrev_a(stack_a, 1);
	    cheap->cost_a++;
	}
	while (cheap->cost_b > 0)
	{
	    rot_b(stack_b, 1);
	    cheap->cost_b--;
	}
	while (cheap->cost_b < 0)
	{
		rotrev_b(stack_b, 1);
		cheap->cost_b++;
	}	
}

ps_list		*cheap_cost(ps_list *stack_b)
{
	ps_list		*tmp;
	ps_list		*cheapest;
	int			total_cost;

	tmp = stack_b;
	cheapest = stack_b;
	while (tmp)
	{
		total_cost = total_cost_calculate(tmp);
		if (total_cost < cheapest->total_cost)
		{
			cheapest = tmp;
			cheapest->total_cost = total_cost;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

int	is_sorted(ps_list *stack)
{
    if (!stack || !stack->next)
        return (1);
    while (stack->next)
    {
        if (stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void	final_order(ps_list **stack_a)
{
	ps_list		*min_number;
	int			size;


	size = ps_lstlen(*stack_a);
	min_number = min_node(*stack_a); 
	while (*stack_a != min_number)
	{
		if (min_number->index <= size / 2)
			rot_a(stack_a, 1);
		else
			rotrev_a(stack_a, 1);
	}
}

void	choose_movs(ps_list **stack_a, ps_list **stack_b)
{
	ps_list		*cheapest;

	
	cheapest = cheap_cost(*stack_b);
	//while (aux_b)
	//{
		double_rotate(stack_a, stack_b, cheapest);
		single_rotate(stack_a, stack_b, cheapest);
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

void	turk(ps_list **stack_a, ps_list **stack_b)
{
	int			size;
	ps_list		*aux;

	aux = *stack_a;
	size = ps_lstlen(aux);
	index_final(*stack_a);
	move_b(stack_a, stack_b, size);
	sort_three(stack_a);
	while (*stack_b)
	{
		update_index(*stack_a, *stack_b);
		target(*stack_a, *stack_b);
		target_index(*stack_b, *stack_a);
		cost_calculate(*stack_a, *stack_b);
		choose_movs(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		final_order(stack_a);	
}
