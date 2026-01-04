/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:17:57 by daniviei          #+#    #+#             */
/*   Updated: 2025/12/23 18:39:21 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# Passo a Passo
**1- Verificar dados de entrada**
[] Verificar duplicadas
[] Verificar se foram passados números dentro do range do INT_MIN >= && <= INT_MAX 
[x] Verificar se todos os inputs são de fatos números
[] Argv[1] sera o topo da lista

*ATENÇÃO*: Se for encontrado caracteres inválidos ou duplicadas retornar error adequadamente.

[] Transformar os dados de entrada de tipo char* para int

Colocar os números int dentro de uma pilha(lista encadeada)

* Os erros incluem, por exemplo:
   alguns argumentos não serem inteiros
   alguns argumentos exceder os limites dos números inteiros e/ou a presença de duplicados
*/
#include "LIBFT/libft.h"
#include <stdio.h>
char	*ft_strchry(const char *s, int c);
/*Acrescentar o argv[i] a uma nova string para usar seus indices*/
char *append_str(char **argv)
{
	int		i;
	char	*temp;
	char	*str2;
	char	*old;

	i = 1;
	temp = ft_strdup("");
	while (argv[i] != NULL)
	{
		if (str2)
		{
			// ver strchry no makefile
			if (ft_strchry(str2, *argv[i]))
			return ("erro");
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

	//append = acrescentar
	if (argc < 2)
	{
		//apagar
		printf("passe os inteiros");
		//
		return(1);
	}
	char *number_list = append_str(argv);
	//free(number_list); posso apagar!
	char **numbers = ft_split(number_list, ' ');
	for (int i = 0; numbers[i] != NULL; i++)
		printf("%s\n", numbers[i]);
	free(numbers);
	//free(temp);

}
