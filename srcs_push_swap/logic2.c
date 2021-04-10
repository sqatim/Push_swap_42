/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/10 01:07:23 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ============================ tani test ============================ */

// je push au stack b le min au max et le repusher to a

/* ============================   play   ============================ */

t_tmp init_tmp(t_stack *a, t_stack *b)
{
    t_tmp tmp;

    tmp.a = a;
    tmp.b = b;
    return (tmp);
}

void chose_operation(t_tmp *tmp, int numb, int if_true)
{
    t_stack *tmp_a;
    t_tools tool;
    static int check;

    if (if_true == 1)
    {
        tmp_a = tmp->a;
        tool.len_a = count_len_stack(tmp_a);
        tool.med_a = tool.len_a / 2;
        if (tool.len_a % 2 != 0)
            tool.med_a++;
        tmp_a = tmp->a;
        tool.count_a = count_to_number(tmp_a, numb);
        tool.diff_a = tool.count_a - tool.med_a;
        check = which_operation(tmp->a, tmp->b, tool);
    }
    if (check == REVERSE_A)
    {
        // puts("===== REVERSE_A =====");
        reverse(&tmp->a, "ra");
        // print(tmp->a, tmp->b);
    }
    else if (check == REVERSE_REVERSE_A)
    {
        // puts("===== REVERSE_REVERSE_A =====");
        reverse_reverse(&tmp->a, "rra");
        // print(tmp->a, tmp->b);
    }
}

t_pivot *select_pivot(t_pivot *pivot, int number)
{
    t_pivot *new;
    t_pivot *tmp;

    if (!(new = (t_pivot *)malloc(sizeof(t_pivot))))
        return (NULL);
    new->next = NULL;
    new->previous = NULL;
    new->pivot = number;
    if (!pivot)
        return (new);
    tmp = pivot;
    while (tmp->next)
        tmp = tmp->next;
    new->previous = tmp;
    tmp->next = new;
    return (pivot);
}
t_pivot *step_zero(t_stack *a)
{
    t_stack *tmp;
    t_stack *change;
    // t_pivot *pivot;
    t_pivot *pivot;
    pivot = NULL;
    int counter = 0;
    int i = 1;
    int index = 0;
    int number;
    int len;
    tmp = a;
    print(a, NULL);
    while (tmp)
    {
        change = tmp->next;
        while (change)
        {
            if (change->number < tmp->number)
            {
                number = tmp->number;
                tmp->number = change->number;
                change->number = number;
            }
            change = change->next;
        }
        tmp = tmp->next;
    }
    tmp = a;
    len = count_len_stack(tmp);
    tmp = a;
    while (tmp)
    {
        if ((i * (len / 5)) == counter)
        {
            pivot = select_pivot(pivot, tmp->number);
            i++;
        }
        counter++;
        tmp = tmp->next;
    }
    // counter = 0;
    // while (pivot)
    // {
    //     printf("|pivot[%d] = %d|\n", counter, pivot->pivot);
    //     counter++;
    //     pivot = pivot->next;
    // }
    return (pivot);
}
void step_one(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_tmp tmp;
    t_stack *tmp_a;
    int if_true = 1;
    int calcul;
    int numb;
    int check;
    t_save save;
    t_tools tool;
    int counter = 0;
    int index = 0;

    // tmp = init_tmp(*a, *b);
    while (index < 4)
    {
        tmp = init_tmp(*a, *b);
        while (counter < pivot->pivot)
        {
            tmp_a = tmp.a;
            if (tmp.a->number <= pivot->pivot)
            {
                push(&tmp.b, &tmp.a, "pb");
                if_true = 1;
                counter++;
            }
            else
            {
                chose_operation(&tmp, numb, if_true);
                if_true = 0;
            }
        }
        pivot = pivot->next;
        index++;
        *b = tmp.b;
        *a = tmp.a;
    }
    // while (pivot)
    // pivot = pivot->previous;
    while (*a)
        push(&*b, &*a, "pb");
    // print(*a, *b);
}

int maximum(t_stack *stack)
{
    int max = INT_MIN;

    while (stack)
    {
        if (stack->number >= max)
            max = stack->number;
        stack = stack->next;
    }
    return (max);
}
void step_two(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_stack *tmp_b;
    t_tmp tmp;
    int max;
    int counter = 0;
    int if_true = 1;

    tmp_b = *b;
    max = maximum(tmp_b);
    // while (index < 19)
    // {
    //     tmp = init_tmp(*a, *b);
    while (counter < 19)
    {
        tmp_b = tmp.b;
        if (tmp.b->number > pivot->pivot)
        {
            push(&tmp.b, &tmp.a, "pb");
            if_true = 1;
            counter++;
        }
        else
        {
            chose_operation(&tmp, numb, if_true);
            if_true = 0;
        }
    }
    pivot = pivot->next;
    index++;
    *b = tmp.b;
    *a = tmp.a;
    // }
    // while (index < 4)
    // {
    //     tmp = init_tmp(*a, *b);
    //     while (counter < pivot->pivot)
    //     {
    //         tmp_a = tmp.a;
    //         if (tmp.a->number <= pivot->pivot)
    //         {
    //             push(&tmp.b, &tmp.a, "pb");
    //             if_true = 1;
    //             counter++;
    //         }
    //         else
    //         {
    //             chose_operation(&tmp, numb, if_true);
    //             if_true = 0;
    //         }
    //     }
    //     pivot = pivot->next;
    //     index++;
    //     *b = tmp.b;
    //     *a = tmp.a;
    // }
}