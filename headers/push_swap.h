/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:27:45 by sqatim            #+#    #+#             */
/*   Updated: 2021/03/27 20:48:22 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_stack
{
    int number;
    struct s_stack *next;
    struct s_stack *previous;
} t_stack;

void swap(t_stack **stack);
void reverse(t_stack **stack);
void push(t_stack **first, t_stack **second);
void reverse_reverse(t_stack **stack);
void rreverse_reverse(t_stack *a, t_stack *b);
void rreverse(t_stack *a, t_stack *b);
void sswap(t_stack *a, t_stack *b);

t_stack *create_node(int number);
t_stack *allocation(t_stack *stack_a, int nbr);

#endif