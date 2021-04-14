/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:27:45 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 23:30:55 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../libft/libft.h"

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"

typedef struct s_pivot
{
    int pivot;
    struct s_pivot *next;
    struct s_pivot *previous;
} t_pivot;

typedef enum e_argument
{
    COLOR,
    SHOW
} t_argument;

typedef enum e_operation
{
    REVERSE,
    REVERSE_REVERSE,
} t_operation;

typedef struct s_stack
{
    int number;
    struct s_stack *next;
    struct s_stack *previous;
} t_stack;

typedef struct s_tmp
{
    t_stack *a;
    t_stack *b;
} t_tmp;

typedef struct s_tools
{
    int med;
    int diff;
    int len;
    int count;
    int pivot;
    int if_true;
    int arg;
    int max;
    int min;
} t_tools;

/*================================  operation  ================================*/
void logic1(t_stack **a, t_stack *b, int arg);
void logic2(t_stack **a, t_stack **b, int len, int arg);
void logic3(t_stack **a, t_stack **b, int arg);
void logic4(t_stack **a, t_stack **b, t_stack *stack, int arg);
t_stack *change_element(t_stack *a);
/*================================  operation  ================================*/

void swap(t_stack **stack1, t_stack *stack2, char *name, int color);
void reverse(t_stack **stack1, t_stack *stack2, char *name, int color);
void push(t_stack **first, t_stack **second, char *name, int color);
void reverse_reverse(t_stack **stack1, t_stack *stack2, char *name, int color);
void rreverse_reverse(t_stack **a, t_stack **b, char *name);
void rreverse(t_stack **a, t_stack **b, char *name);
void sswap(t_stack **a, t_stack **b, char *name);

/*================================  allocation  ================================*/

t_stack *create_node(int number);
t_stack *allocation(t_stack *stack_a, int nbr);
t_pivot *select_pivot(t_pivot *pivot, int number);

/*================================  check  ================================*/

void check_for_duplicates(t_stack *a, t_stack *stack);
t_stack *check_affec(int ac, char **av, t_stack *a, t_stack **stack);
// t_stack *check_affec(int ac, char **av, t_stack *a);
int check_tri(t_stack *a, t_stack *b);

/*================================  read  ================================*/

void read_instructions(t_stack **a, t_stack **b);

/*================================  search  ================================*/

int search_for_pivot(t_stack *a, int *calcul);

/*================================  search  ================================*/

int calcul_for_reverse(t_stack *a);

/*================================  tool     ================================*/

int count_to_number(t_stack *stack, int number);
int count_len_stack(t_stack *stack);
int count_len_pivot(t_pivot *pivot);
void chose_operation(t_stack **stack1, t_stack *stack2, t_tools tool, char c);
t_tmp init_tmp(t_stack *a, t_stack *b);
void chose_operation_a(t_tmp *tmp, int numb, int if_true);
void chose_operation_b(t_tmp *tmp, int numb, int if_true);
int which_operation(int diff);
int minimum(t_stack *stack);
int maximum(t_stack *stack);
char **ft_space_split(char const *s);
long long ft_atol(const char *str);
int check_arg(char *str);

/*================================  free  ================================*/

void free_string(char **str);
void free_stack(t_stack **stack);
void free_2_stack(t_stack **a, t_stack **b);
void free_tab(char ***tab);
void free_pivot(t_pivot **pivot);

/*================================  print  ================================*/

void print(t_stack *a, t_stack *b);

#endif