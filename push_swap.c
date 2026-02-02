/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:17:57 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/20 12:27:45 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//MOVER 3 FUNCOES
/* APAGAR NO FINAL!!!
void	print_stack(t_push *stack)
{
	t_push	*aux;

	aux = stack;
	while (aux)
	{
		int	listValue = aux->content;
		printf("index: %d nó %d\n", aux->index, listValue);
		aux = aux->next;
		if (aux == stack)
			break ;
	}
}*/

static char	*append_str(char **argv)
{
	int		i;
	char	*temp;
	char	*str2;
	char	*old;

	i = 1;
	temp = ft_strdup("");
	while (argv[i] != NULL)
	{
		if (verify(argv[i]))
		{
			ft_putendl_fd("Error", 2);
			free(temp);
			return (NULL);
		}
		str2 = ft_strjoin(argv[i], " ");
		old = temp;
		temp = ft_strjoin(old, str2);
		free(str2);
		free(old);
		i++;
	}
	return (temp);
}

void	join(t_push **holder, char *buf)
{
	t_push		*new_node;
	t_push		*last_node;
	int			value;

	last_node = ps_lstlast(*holder);
	new_node = malloc(sizeof(t_push));
	if (new_node == NULL)
		return ;
	value = ft_atoi(buf);
	if (*holder == NULL)
	{
		*holder = new_node;
		new_node->prev = NULL;
	}
	else
		last_node->next = new_node;
	new_node->content = value;
	new_node->next = NULL;
	new_node->prev = last_node;
}

void	double_list(t_push *holder)
{
	t_push		*last_node;

	last_node = ps_lstlast(holder);
	holder->prev = last_node;
}

int	main(int argc, char **argv)
{
	char	*number_list;
	char	**numbers;
	t_push	*a;
	t_push	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	number_list = append_str(argv);
	if (number_list == NULL)
		exit(1);
	numbers = ft_split(number_list, ' ');
	free(number_list);
	if (numbers == NULL)
	{
		ft_putendl_fd ("Error", 2);
		return (1);
	}
	check_double(numbers);
	append_lst(&a, numbers);
	double_list(a);
	if (ps_lstlen(a) > 1 && !is_sorted(a))
		sort_stack(&a, &b);
	free_list(&a);
}
