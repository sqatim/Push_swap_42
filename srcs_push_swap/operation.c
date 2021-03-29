/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:34:44 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/03/29 17:54:14 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    t_stack *tmp;
    t_stack *test;

    if (*stack)
    {
        if ((*stack)->next)
        {
            tmp = (*stack);
            (*stack) = (*stack)->next;
            tmp->next = (*stack)->next;
            if (tmp->next && tmp->next->previous)
                tmp->next->previous = tmp;
            (*stack)->previous = NULL;
            (*stack)->next = tmp;
            test = *stack;
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void sswap(t_stack **a, t_stack **b)
{
    swap(&(*a));
    swap(&(*b));
}
void reverse(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    if (!(*stack))
        ft_putendl_fd("stack is empty", 1);
    else
    {
        if ((*stack)->next)
        {
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
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void rreverse(t_stack **a, t_stack **b)
{
    reverse(&(*a));
    reverse(&(*b));
}

void push(t_stack **first, t_stack **second)
{
    t_stack *new;
    t_stack *tmp;
    tmp = NULL;

    // ft_putendl_fd("i am here",1);
    // printf("number -> %d\n",(*second)->number);
    if (*second == NULL)
        ft_putendl_fd("Second Tab is empty", 1);
    else
    {
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
}

void reverse_reverse(t_stack **stack)
{
    t_stack *tmp;

    if (!(*stack))
        ft_putendl_fd("stack is empty", 1);
    else
    {
        if ((*stack)->next)
        {
            tmp = *stack;
            while (tmp->next)
                tmp = tmp->next;
            (*stack)->previous = tmp;
            tmp->next = *stack;
            tmp->previous->next = NULL;
            tmp->previous = NULL;
            *stack = tmp;
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void rreverse_reverse(t_stack **a, t_stack **b)
{
    reverse_reverse(&(*a));
    reverse_reverse(&(*b));
}
