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

/*
# Passo a Passo
**1- Verificar dados de entrada**
[x] Verificar duplicadas
[x] Verificar se foram passados números dentro do range do INT_MIN >= && <= INT_MAX 
[x] Verificar se todos os inputs são de fatos números
[x] Argv[1] sera o topo da lista:

*ATENÇÃO*: Se for encontrado caracteres inválidos ou duplicadas retornar error adequadamente.

[x] Transformar os dados de entrada de tipo char* para int

[x] Colocar os números int dentro de uma pilha(lista encadeada)"coloquei na lista mas como char ainda"

[ ] Ordenar caso sega so dois ou tres argumentos
[ ] Ordenar os valores na pilha 'a' usando a pilha 'b'


* Os erros incluem, por exemplo:
 [x] alguns argumentos não serem inteiros
 [x] alguns argumentos exceder os limites dos números inteiros e/ou a presença de duplicados
*/
#include "push_swap.h"
#include <stdio.h>
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
void	join(t_list **holder, char *buf)
{
	t_list  *new_node;
	t_list  *last_node;
	int		*value;
	
	last_node = ft_lstlast(*holder);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	value = malloc(sizeof (int));
	if (value == NULL)
	{
		free(value);
		return ;
	}
	*value = ft_atoi(buf);
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

/*static */void cicle_list(t_list *holder)
{
	t_list  *last_node;

	last_node = ft_lstlast(holder);
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
	t_list *a = NULL;
	t_list *b = NULL;
	
	if (argc < 2)
	{
		//ver qual é o erro a ser mostrado
		printf("passe os inteiros\n");
		return(1);
	}
	//append = acrescentar
	char *number_list = append_str(argv);
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
	cicle_list(a);
	sort_stack(a, b);
	//aux p n perder a referencia da cabeca da lista
	t_list *aux = a;
	
	while (aux) {
		int	listValue = *(int *)aux->content;
	// posso passar sem armazenar em var pro printf tbm.
		printf("nó da lista %d\n", listValue);
		aux = aux->next;
		if (aux == a)
			break ;
	}
	free_matrix(numbers);
}
