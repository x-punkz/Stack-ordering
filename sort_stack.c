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
	t_list	*aux;

	count = 1;
	aux = lst;
	while (aux->next)
	{
		if (aux->next == lst)
			break ;
		aux = aux->next;
		count++;
	}
	return (count);
}

void	sort_three(t_list *stack_a)
{
	t_list	*a;

	a = stack_a;
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

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	while(*(int *)stack_a->content != min_node(stack_a))
		rot_a(stack_a);
	push_b(&stack_a, &stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

/*void	sort_five(t_list *stack_a, t_list *stack_b)
{
	
}*/

int		min_node(t_list *stack)
{
	int		min;
	t_list	*aux;

	aux = stack;
	min = *(int *)aux->content;
	while(aux->next)
	{
		if (min > *(int *)aux->content)
			min = *(int *)aux->content;
		aux = aux->next;
		if (aux == stack)
			break ;
	}
	return (min);
}

int		max_node(t_list *stack)
{	int		max;
	t_list	*aux;

	max = 0;
	aux = stack;
	while(aux->next != stack)
	{
		if (max > *(int *)aux->content)
			max = *(int *)aux->content;
		aux = aux->next;
	}
	return (max);
}

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstlen(stack_a) < 6)
	{	
		if (ft_lstlen(stack_a) == 3)
			sort_three(stack_a);
		if (ft_lstlen(stack_a) == 4)
			sort_four(stack_a, stack_b);
//		if (ft_lstlen(stack_a) == 5)
//			sort_five(stack_a, stack_b);

	}
//	else
//		algoritimo_de_ordenar(stack_a, stack_b);

}
