/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:27:45 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/07 18:31:39 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../libft/libft.h"

typedef enum e_operation
{
    SWAP_A,
    SWAP_B,
    SSWAP,
    REVERSE_A,
    REVERSE_B,
    RREVERSE,
    REVERSE_REVERSE_A,
    REVERSE_REVERSE_B,
    RREVERSE_REVERSE,
    PUSH_A,
    PUSH_B
}           t_operation;

typedef struct s_save
{
    int min_a;
    int max_a;
    int min_b;
    int max_b;
    int min;
    int max;
}                   t_save;


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
}               t_tmp;

typedef struct s_tools
{
    int med_a;
    int med_b;
    int diff_a;
    int diff_b;
    int len_a;
    int len_b;
}               t_tools;


/*================================  operation  ================================*/

void swap(t_stack **stack);
void reverse(t_stack **stack);
void push(t_stack **first, t_stack **second);
void reverse_reverse(t_stack **stack);
void rreverse_reverse(t_stack **a, t_stack **b);
void rreverse(t_stack **a, t_stack **b);
void sswap(t_stack **a, t_stack **b);

/*================================  steps  ================================*/

void step_one(t_stack **a, t_stack **b);
void step_two(t_stack **a, t_stack **b);

/*================================  allocation  ================================*/

t_stack *create_node(int number);
t_stack *allocation(t_stack *stack_a, int nbr);

/*================================  check  ================================*/

void check_for_duplicates(t_stack *a);
t_stack *check_affec(int ac, char **av, t_stack *a);
int check_tri(t_stack *a, t_stack *b);

/*================================  read  ================================*/

void read_instructions(t_stack **a, t_stack **b);

/*================================  search  ================================*/

int search_for_pivot(t_stack *a, int *calcul);

/*================================  search  ================================*/

int calcul_for_reverse(t_stack *a);

/*================================  search  ================================*/

int count_to_number(t_stack *stack, int number);
int count_len_stack(t_stack *stack);

/*================================  free  ================================*/

void free_string(char **str);
void free_stack(t_stack **stack);
void free_2_stack(t_stack **a, t_stack **b);

/*================================  print  ================================*/

void print(t_stack *a, t_stack *b);

#endif