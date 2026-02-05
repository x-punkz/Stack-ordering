/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:57:10 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/27 14:57:54 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_lstadd_front(t_push **lst, t_push *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_push	*ps_lstlast(t_push *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_push	*ps_lstnew(int content)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	is_sorted(t_push *stack)
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

void	check_program(t_push **stack_a, t_push **stack_b, char **matrix)
{
	char	*mov;

	mov = get_next_line(0);
	while (mov)
	{
		if (!check_output(mov, stack_a, stack_b))
		{
			free_matrix(matrix);
			free(mov);
			free_list(stack_a);
			free_list(stack_b);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(mov);
		mov = get_next_line(0);
	}
	if (!is_sorted(*stack_a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	free_matrix(matrix);
	free(mov);
}
