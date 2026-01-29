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
#include <stdio.h>

void	print_stack(ps_list *stack)
{
	//apvoid	print_stack(ps_list *stack);//apagar esta funçaoagar est funçao!!!
	ps_list *aux = stack;

	while (aux)
	{
		int	listValue = aux->content;
// posso passar sem armazenar em var pro printf tbm.
		printf("index: %d nó %d\n", aux->index, listValue);
		aux = aux->next;
		if (aux == stack)
			break ;
	}
}

static int	verify(char *arg)
{
	int		i;
	long	argx;

	i = 0;
	argx = ft_atol(arg);
	if (argx < -2147483648 || argx > 2147483647)
		return (1);
	while (arg[i])
	{	//verica se tem algum valor igual no argv
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == ' ')
			i++;
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return(0);
}
/*Acrescentar o argv[i] a uma nova string para usar seus indices*/
static char *append_str(char **argv)
{
	int		i;
	char	*temp;
	char	*str2;
	char	*old;

	i = 1;
	temp = ft_strdup("");
	//Fazer outras verificacoes
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
// adicionar elementos na pilha
void	join(ps_list **holder, char *buf)
{
	ps_list  *new_node;
	ps_list  *last_node;
	int		value;
	
	last_node = ps_lstlast(*holder);
	new_node = malloc(sizeof(ps_list));
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

void double_list(ps_list *holder)
{
	ps_list  *last_node;

	last_node = ps_lstlast(holder);
	holder->prev = last_node;
	//last_node->next = holder;
}

void free_matrix(char **str)
{
	int i;

	i = 0;
	while(str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int	main(int argc, char **argv)
{
	int	i;
	int	j;
	ps_list *a = NULL;
	ps_list *b = NULL;
	
	if (argc < 2)
	{
		//ver qual é o erro a ser mostrado
		printf("passe os inteiros\n");
		return(1);
	}
	//append = acrescentar
	//ver caso de argv == " "
	char *number_list = append_str(argv);
	if (number_list == NULL)
		exit(1);
	char **numbers = ft_split(number_list, ' ');
	if (numbers == NULL)
	{
		ft_putendl_fd ("Error", 2);
		return (1);
	}
	i = 0;
	// verificaçao de valores iguais
	while (numbers[i] != NULL)
	{
		j = i + 1;
		while (numbers[j] != NULL)
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
			{
				ft_putendl_fd ("Error", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (numbers[i] != NULL)
	{
		join(&a, numbers[i]);
		i++;
	}
	update_index(a);
	double_list(a);
	if (ps_lstlen(a) > 1)
		sort_stack(&a, &b);
	//aux p n perder a referencia da cabeca da lista
	print_stack(a);

	free_matrix(numbers);
}
