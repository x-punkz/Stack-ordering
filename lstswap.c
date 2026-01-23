/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstswap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:20:30 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/20 18:20:36 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	lstswap(t_list *stack)
{
	t_list	*tmp;

	tmp = ft_lstnew("");
	tmp->content = stack->next->content;
	stack->next->content = stack->content;
	stack->content = tmp->content;
}

void	swap_a(t_list *a)
{
	lstswap(a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list *b)
{
	lstswap(b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ss(t_list *a, t_list *b)
{
	lstswap(a);
	lstswap(b);
	ft_putstr_fd("ss\n", 1);
}

void	rot_a(t_list *a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !(a)->next)
		return ;
	first = ft_lstnew(a->content);
	*a = *a->next;
		// 4. Encontra o último elemento da lista
	last = a;
	while (last->next)
	{
		last = last->next;
		if (last->next == a)
			break ;
	}
	
	// 5. Move o primeiro elemento para o final
	last->next = first;
	first->prev = last;
	a->prev = first;
	first->next = NULL;
	

	/*t_list	*tmp;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = a->prev->content;
	a->prev->content = tmp;*/
	ft_putstr_fd("ra\n", 1);
}

void	rotrev_a(t_list *a)
{
	t_list	*tmp;

	tmp = a->content;
	a->content = a->prev->content;
	a->prev->content = a->next->content;
	a->next->content = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rot_b(t_list *b)
{
	t_list	*tmp;

	tmp = b->content;
	b->content = b->next->content;
	b->next->content = b->prev->content;
	b->prev->content = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rotrev_b(t_list *b)
{
	t_list	*tmp;

	tmp = b->content;
	b->content = b->prev->content;
	b->prev->content = b->next->content;
	b->next->content = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	rot_ab(t_list *a, t_list *b)
{
	rot_a(a);
	rot_b(b);
	ft_putstr_fd("rr\n", 1);
}

void	rotrev_ab(t_list *a, t_list *b)
{
	rotrev_a(a);
	rotrev_b(b);
	ft_putstr_fd("rrr\n", 1);
}
/*pega o topo de b e joga pro topo de a*/
void   push_a(t_list *a, t_list *b)
{
    t_list	*tmp;
	t_list	*last;

	if (b == NULL)
        return ;
    // mudando a cabeça de b
	tmp = ft_lstnew(b->content);
    if (b->next)
		*b = *b->next;
	last = b;
	while (last->next)
	{
		last = last->next;
		if (last->next == b)
			break ;
	}
	//Atualiza o prev do novo top_B
	if (b)
		b->prev = last;
	//coloca no topo de b
	tmp->next = a;
	if (a)
		a->prev = tmp;
	a = tmp;
	tmp->prev = ft_lstlast(a);
    ft_putstr_fd("pa\n", 1);
}

/*Pega o top de a e joga p topo de b*/
void   push_b(t_list **a, t_list **b)
{
    t_list	*tmp;
	t_list	*last;

	if (a == NULL)
        return ;
    // mudando a cabeca de a
	tmp = ft_lstnew(a);
	*a = (*a)->next;
	last = *a;
	while (last->next)
	{
		last = last->next;
		if (last->next == *a)
			break ;
	}
	//Atualiza o prev do novo top_A
	if (a)
		(*a)->prev = last;
	//coloca no topo de b
	//if (b)
	//	(*b)->prev = tmp;
	ft_lstadd_front(b, tmp);
	(*b)->prev = ft_lstlast((*b)->content);
    ft_putstr_fd("pb\n", 1);
}