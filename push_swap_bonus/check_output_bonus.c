/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_output_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:57:10 by daniviei          #+#    #+#             */
/*   Updated: 2026/01/27 14:57:54 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_output(char *mov, t_push **stack_a, t_push **stack_b)
{
	if (ft_strcmp(mov, "sa\n") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(mov, "sb\n") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(mov, "ss\n") == 0)
		swap_ss(stack_a, stack_b);
	else if (ft_strcmp(mov, "pa\n") == 0)
		push_a(stack_a, stack_b);
	else if (ft_strcmp(mov, "pb\n") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(mov, "ra\n") == 0)
		rot_a(stack_a);
	else if (ft_strcmp(mov, "rb\n") == 0)
		rot_b(stack_b);
	else if (ft_strcmp(mov, "rr\n") == 0)
		rot_ab(stack_a, stack_b);
	else if (ft_strcmp(mov, "rra\n") == 0)
		rotrev_a(stack_a);
	else if (ft_strcmp(mov, "rrb\n") == 0)
		rotrev_b(stack_b);
	else if (ft_strcmp(mov, "rrr\n") == 0)
		rotrev_ab(stack_a, stack_b);
	else
		return (0);
	return (1);
}

char	*join_free(char **s1, char *s2)
{
	int		i;
	int		ni;
	size_t	size;
	char	*nstr;

	i = 0;
	ni = 0;
	size = (ft_strlen(s1[0]) + ft_strlen(s2)) * sizeof(char);
	nstr = (char *)malloc(size + 1);
	if (!nstr)
		return (NULL);
	while (s1[0][i] != '\0')
	{
		nstr[ni] = s1[0][i];
		ni++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		nstr[ni++] = s2[i++];
	}
	nstr[ni] = '\0';
	free(s1[0]);
	return (nstr);
}
