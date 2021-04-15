/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:52:29 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/15 23:52:30 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef enum	e_argument
{
	DEBUGGER,
}				t_argument;

typedef struct	s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

t_stack		*create_node(int number);
t_stack		*allocation(t_stack *stack_a, int nbr);
t_stack		*check_affec(int ac, char **av, t_stack *a, int *arg);
void		swap(t_stack **stack, int arg);
void		reverse(t_stack **stack, int arg);
void		push(t_stack **first, t_stack **second, int arg);
void		reverse_reverse(t_stack **stack, int arg);
void		rreverse_reverse(t_stack **a, t_stack **b, int arg);
void		rreverse(t_stack **a, t_stack **b, int arg);
void		sswap(t_stack **a, t_stack **b, int arg);
void		check_for_duplicates(t_stack *a);
void		read_instructions(t_stack **a, t_stack **b, int arg);
void		free_string(char **str);
void		free_stack(t_stack **stack);
void		free_2_stack(t_stack **a, t_stack **b);
void		free_tab(char ***tab);
char		**ft_space_split(char const *s);
int			check_if_int(char *str);
long long	ft_atol(const char *str);
void		print(t_stack *a, t_stack *b);

#endif
