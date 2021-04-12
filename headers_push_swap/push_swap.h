/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:27:45 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/12 18:23:58 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_pivot
{
    int pivot;
    struct s_pivot *next;
    struct s_pivot *previous;
} t_pivot;

typedef enum e_operation
{
    SWAP,
    SSWAP,
    REVERSE,
    REVERSE_A,
    RREVERSE,
    REVERSE_REVERSE,
    REVERSE_REVERSE_A,
    RREVERSE_REVERSE,
    PUSH_A,
    PUSH_B
} t_operation;

typedef struct s_save
{
    int min_a;
    int max_a;
    int min_b;
    int max_b;
    int min;
    int max;
} t_save;

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
    int med_a;
    int med_b;
    int diff;
    int diff_a;
    int diff_b;
    int len;
    int len_a;
    int count;
    int count_a;
    int count_b;
} t_tools;


/*================================  operation  ================================*/
void logic1(t_stack **a);
void logic2(t_stack **a, t_stack **b, t_stack *stack ,int len);
void logic3(t_stack **a, t_stack **b, t_stack *stack, int len);
void logic4(t_stack **a, t_stack **b, t_stack *stack, int len);
t_stack *change_element(t_stack *a);
/*================================  operation  ================================*/

void swap(t_stack **stack, char *name);
void reverse(t_stack **stack, char *name);
void push(t_stack **first, t_stack **second, char *name);
void reverse_reverse(t_stack **stack, char *name);
void rreverse_reverse(t_stack **a, t_stack **b, char *name);
void rreverse(t_stack **a, t_stack **b, char *name);
void sswap(t_stack **a, t_stack **b, char *name);

/*================================  steps  ================================*/
// t_pivot *step_zero(t_stack *a);
// void step_one(t_stack **a, t_stack **b, t_pivot *pivot);
// // void step_one(t_stack **a, t_stack **b);
// void step_two(t_stack **a, t_stack **b, t_pivot *pivot);
// // void step_two(t_stack **a, t_stack **b);
// void step_tree(t_stack **a, t_stack **b, t_pivot *pivot);

/*================================  allocation  ================================*/

t_stack *create_node(int number);
t_stack *allocation(t_stack *stack_a, int nbr);

/*================================  check  ================================*/

void check_for_duplicates(t_stack *a);
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
void chose_operation(t_stack **stack, int numb, int if_true, char c);
t_tmp init_tmp(t_stack *a, t_stack *b);
void chose_operation_a(t_tmp *tmp, int numb, int if_true);
void chose_operation_b(t_tmp *tmp, int numb, int if_true);
int which_operation(int diff);
int minimum(t_stack *stack);
int maximum(t_stack *stack);

/*================================  free  ================================*/

void free_string(char **str);
void free_stack(t_stack **stack);
void free_2_stack(t_stack **a, t_stack **b);

/*================================  print  ================================*/

void print(t_stack *a, t_stack *b);

#endif