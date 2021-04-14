/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:27:45 by sqatim            #+#    #+#             */
/*   Updated: 2021/03/28 12:46:44 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "get_next_line_bonus.h"

typedef struct s_stack
{
    int number;
    struct s_stack *next;
    struct s_stack *previous;
} t_stack;

/*================================  operation  ================================*/

void swap(t_stack **stack);
void reverse(t_stack **stack);
void push(t_stack **first, t_stack **second);
void reverse_reverse(t_stack **stack);
void rreverse_reverse(t_stack **a, t_stack **b);
void rreverse(t_stack **a, t_stack **b);
void sswap(t_stack **a, t_stack **b);

/*================================  allocation  ================================*/

t_stack *create_node(int number);
t_stack *allocation(t_stack *stack_a, int nbr);

/*================================  check  ================================*/

void check_for_duplicates(t_stack *a);
t_stack *check_affec(int ac, char **av, t_stack *a);

/*================================  read  ================================*/

void read_instructions(t_stack **a, t_stack **b);

/*================================  free  ================================*/

void free_string(char **str);
void free_stack(t_stack **stack);
void free_2_stack(t_stack **a, t_stack **b);

/*================================  tools  ================================*/

char **ft_space_split(char const *s);
long long ft_atol(const char *str);

/*================================  print  ================================*/

void print(t_stack *a, t_stack *b);

#endif