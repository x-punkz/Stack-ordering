/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:56:05 by daniviei          #+#    #+#             */
/*   Updated: 2025/12/23 18:05:56 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"
# include "get_next_line_bonus.h"
# include <limits.h>

typedef struct s_push
{
	int				content;
	struct s_push	*next;
	struct s_push	*target;
	int				index;
	int				total_cost;
	int				target_index;
	int				cost_a;
	int				cost_b;
	int				index_final;
	struct s_push	*prev;
}					t_push;

char				*get_next_line(int fd);
int					check_output(char *mov, t_push **stack_a, t_push **stack_b);
void				check_program(t_push **stack_a, t_push **stack_b,
						char **matrix);
void				free_list(t_push **list);
void				free_matrix(char **str);
int					verify(char *arg);
int					check_double(char **matrix);
void				join(t_push **holder, char *buf);
void				append_lst(t_push **stack_a, char **matrix);
int					ps_lstlen(t_push *lst);
void				swap_a(t_push **a);
void				swap_b(t_push **b);
void				swap_ss(t_push **a, t_push **b);
void				rot_a(t_push **a);
void				rot_b(t_push **b);
void				rot_ab(t_push **a, t_push **b);
void				rotrev_a(t_push **a);
void				rotrev_b(t_push **b);
void				rotrev_ab(t_push **a, t_push **b);
void				lstswap(t_push **stack);
void				push_a(t_push **a, t_push **b);
void				push_b(t_push **a, t_push **b);
int					is_sorted(t_push *stack);
void				ps_lstadd_back(t_push **lst, t_push *new);
t_push				*ps_lstlast(t_push *lst);
t_push				*ps_lstnew(int content);
void				ps_lstadd_front(t_push **lst, t_push *new);
char				*ps_strjoin(char **s1, char const *s2);
#endif
