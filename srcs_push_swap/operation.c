/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:34:44 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/12 12:01:01 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack, char *name)
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
            if (name)
                ft_putendl_fd(name, 1);
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void sswap(t_stack **a, t_stack **b, char *name)
{
    swap(&(*a), NULL);
    swap(&(*b), NULL);
    ft_putendl_fd(name, 1);
}
void reverse(t_stack **stack, char *name)
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
            if (name)
                ft_putendl_fd(name, 1);
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void rreverse(t_stack **a, t_stack **b, char *name)
{
    reverse(&(*a), NULL);
    reverse(&(*b), NULL);
    ft_putendl_fd(name, 1);
}

void push(t_stack **first, t_stack **second, char *name)
{
    t_stack *new;
    t_stack *tmp;
    tmp = NULL;

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
        if (name)
            ft_putendl_fd(name, 1);
    }
}

void reverse_reverse(t_stack **stack, char *name)
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
            if (name)
                ft_putendl_fd(name, 1);
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void rreverse_reverse(t_stack **a, t_stack **b, char *name)
{
    reverse_reverse(&(*a), NULL);
    reverse_reverse(&(*b), NULL);
    if (name)
        ft_putendl_fd(name, 1);
}
