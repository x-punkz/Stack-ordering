/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:17:57 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/13 12:22:55 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# Passo a Passo
**1- Verificar dados de entrada**
[ ] Verificar duplicadas
[x] Verificar se foram passados números dentro do range do INT_MIN >= && <= INT_MAX 
[x] Verificar se todos os inputs são de fatos números
[] Argv[1] sera o topo da lista:

*ATENÇÃO*: Se for encontrado caracteres inválidos ou duplicadas retornar error adequadamente.

[] Transformar os dados de entrada de tipo char* para int

[] Colocar os números int dentro de uma pilha(lista encadeada)

* Os erros incluem, por exemplo:
 [] alguns argumentos não serem inteiros
 [] alguns argumentos exceder os limites dos números inteiros e/ou a presença de duplicados
*/
#include "libft/libft.h"
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
			ft_putendl_fd("Error", 2);i = 1;
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
/*static void	join(t_list **holder, char *buf)
{
	t_list  *new_node;
	t_list  *last_node;

	last_node = ft_lstlast(*holder);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (*holder == NULL)
		*holder = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}*/


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
//	t_list **str = NULL;
	//append = acrescentar
	if (argc < 2)
	{
		//apagar
		printf("passe os inteiros\n");
		//
		return(1);
	}
	char *number_list = append_str(argv);
	if (!number_list)
	return (1);
	char **numbers = ft_split(number_list, ' ');
	i = 0;
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
	//while (numbers[i] != NULL)
	//	join(str, numbers[i]);
	// ! isso é p imprimir os numeros !
		for (int i = 0; numbers[i] != NULL; i++)
			printf("%s\n", numbers[i]);
	
	free(numbers);

}
