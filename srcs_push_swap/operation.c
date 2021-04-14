/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:34:44 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 22:06:31 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack1, t_stack *stack2, char *name, int arg)
{
    t_stack *tmp;

    if (*stack1)
    {
        if ((*stack1)->next)
        {
            tmp = (*stack1);
            (*stack1) = (*stack1)->next;
            tmp->next = (*stack1)->next;
            if (tmp->next && tmp->next->previous)
                tmp->next->previous = tmp;
            (*stack1)->previous = NULL;
            (*stack1)->next = tmp;
            if (name)
            {
                if (arg == COLOR)
                    ft_putstr_fd(CYAN, 1);
                ft_putendl_fd(name, 1);
            }
            if (arg == SHOW)
            {
                system("clear");
                if (name[1] == 'a')
                    print(*stack1, stack2);
                else
                    print(stack2, *stack1);
                sleep(1);
            }
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void sswap(t_stack **a, t_stack **b, char *name)
{
    swap(&(*a), NULL, 0, -1);
    swap(&(*b), NULL, 0, -1);
    ft_putendl_fd(name, 1);
}
void reverse(t_stack **stack1, t_stack *stack2, char *name, int arg)
{
    t_stack *tmp;
    t_stack *last;

    if (!(*stack1))
        ft_putendl_fd("stack is empty", 1);
    else
    {
        if ((*stack1)->next)
        {
            tmp = (*stack1);
            *stack1 = (*stack1)->next;
            (*stack1)->previous = NULL;
            last = *stack1;
            while (last->next)
                last = last->next;
            tmp->next = NULL;
            tmp->previous = last;
            last->next = tmp;
            if (name)
            {
                if (arg == COLOR)
                    ft_putstr_fd(GREEN, 1);
                ft_putendl_fd(name, 1);
            }
            if (arg == SHOW)
            {
                system("clear");
                if (name[1] == 'a')
                    print(*stack1, stack2);
                else
                    print(stack2, *stack1);
                sleep(1);
            }
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void rreverse(t_stack **a, t_stack **b, char *name)
{
    reverse(&(*a), NULL, 0, -1);
    reverse(&(*b), NULL, 0, -1);
    ft_putendl_fd(name, 1);
}

void push(t_stack **first, t_stack **second, char *name, int arg)
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
        {
            if (arg == COLOR)
                ft_putstr_fd(YELLOW, 1);
            ft_putendl_fd(name, 1);
        }
        if (arg == SHOW)
        {
            system("clear");
            if (name[1] == 'a')
                print(*first, *second);
            else
                print(*second, *first);
            sleep(1);
        }
    }
}

void reverse_reverse(t_stack **stack1, t_stack *stack2, char *name, int arg)
{
    t_stack *tmp;

    if (!(*stack1))
        ft_putendl_fd("stack is empty", 1);
    else
    {
        if ((*stack1)->next)
        {
            tmp = *stack1;
            while (tmp->next)
                tmp = tmp->next;
            (*stack1)->previous = tmp;
            tmp->next = *stack1;
            tmp->previous->next = NULL;
            tmp->previous = NULL;
            *stack1 = tmp;
            if (name)
            {
                if (arg == COLOR)
                    ft_putstr_fd(RED, 1);
                ft_putendl_fd(name, 1);
            }
            if (arg == SHOW)
            {
                system("clear");
                if (name[2] == 'a')
                    print(*stack1, stack2);
                else
                    print(stack2, *stack1);
                sleep(1);
            }
        }
        else
            ft_putendl_fd("you need at least 2 number in the stack", 1);
    }
}

void rreverse_reverse(t_stack **a, t_stack **b, char *name)
{
    reverse_reverse(&(*a), NULL, 0, -1);
    reverse_reverse(&(*b), NULL, 0, -1);
    if (name)
        ft_putendl_fd(name, 1);
}
