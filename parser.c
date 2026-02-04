/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:17:57 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/20 12:27:45 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	verify(char *arg)
{
	int		i;
	long	argx;

	i = 0;
	argx = ft_atol(arg);
	if (argx < -2147483648 || argx > 2147483647)
		return (1);
	if (!arg || !arg[i])
		return (1);
	while (arg[i] != '\0')
	{
		while (arg[i] == ' ')
			i++;
		if (arg[i] == '+' || arg[i] == '-')
			i++;
		if (arg[i] != '\0' && !ft_isdigit(arg[i]))
			return (1);
		if (arg[i] != '\0')
			i++;
	}
	return (0);
}

void	free_list(t_push **list)
{
	t_push	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list));
		*list = tmp;
	}
	*list = NULL;
}

void	free_matrix(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_double(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i] != NULL)
	{
		j = i + 1;
		while (matrix[j] != NULL)
		{
			if (ft_strcmp(matrix[i], matrix[j]) == 0)
			{
				ft_putendl_fd ("Error", 2);
				free_matrix(matrix);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	append_lst(t_push **stack_a, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		join(stack_a, matrix[i]);
		i++;
	}
	free_matrix(matrix);
}
