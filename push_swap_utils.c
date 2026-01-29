/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:57:10 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/27 14:57:54 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ps_lstadd_front(ps_list **lst, ps_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

ps_list	*ps_lstlast(ps_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

ps_list	*ps_lstnew(int content)
{
	ps_list	*node;

	node = (ps_list *) malloc(sizeof (ps_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
