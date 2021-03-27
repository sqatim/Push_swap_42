/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:34:44 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/03/27 20:41:38 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    t_stack *tmp;
    t_stack *test;

    tmp = (*stack);
    (*stack) = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->next->previous = tmp;
    (*stack)->previous = NULL;
    (*stack)->next = tmp;
    test = *stack;
}

void sswap(t_stack *a, t_stack *b)
{
    swap(&a);
    swap(&b);
}
void reverse(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    tmp = (*stack);
    *stack = (*stack)->next;
    (*stack)->previous = NULL;
    last = *stack;
    while (last->next)
        last = last->next;
    tmp->next = NULL;
    tmp->previous = last;
    last->next = tmp;
}

void rreverse(t_stack *a, t_stack *b)
{
    reverse(&a);
    reverse(&b);
}

void push(t_stack **first, t_stack **second)
{
    t_stack *new;
    t_stack *tmp;
    tmp = NULL;

    if (*second == NULL)
    {
        ft_putendl_fd("Second Tab is empty", 1);
        exit(1);
    }
    new = create_node((*second)->number);
    if (*first)
    {
        new->next = *first;
        (*first)->previous = new;
    }
    *first = new;
    if ((*second)->next)
        tmp = (*second)->next;
    free(*second);
    *second = NULL;
    if (tmp)
        *second = tmp;
}

void reverse_reverse(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    (*stack)->previous = tmp;
    tmp->next = *stack;
    tmp->previous->next = NULL;
    tmp->previous = NULL;
    *stack = tmp;
}

void rreverse_reverse(t_stack *a, t_stack *b)
{
    reverse_reverse(&a);
    reverse_reverse(&b);
}