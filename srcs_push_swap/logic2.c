/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/07 18:47:37 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ============================ tani test ============================ */
/* ============================   play   ============================ */

t_tmp init_tmp(t_stack *a, t_stack *b)
{
    t_tmp tmp;

    tmp.a = a;
    tmp.b = b;
    return (tmp);
}

// je go n9assi o nji nkamal hna
int search_for_min(t_save save, t_stack *stack)
{
    int min;

    min = save.min_b;
    while (stack)
    {
        if (stack->number <= min && stack->number >= save.min_b && stack->number <= save.max_b)
            min = stack->number;
        stack = stack->next;
    }
    return (min);
}
int search_for_max(t_save save, t_stack *stack)
{
    int max;

    max = save.min_a;
    while (stack)
    {
        if (stack->number >= max && stack->number >= save.min_a && stack->number <= save.max_a)
            max = stack->number;
        stack = stack->next;
    }
    return (max);
}

t_save search_for_minmax(t_stack *a, t_stack *b)
{
    t_save save;

    save.min = INT_MAX;
    save.max = INT_MIN;
    while (a)
    {
        if (a->number < save.min)
            save.min = a->number;
        if (a->number > save.max)
            save.max = a->number;
        a = a->next;
    }
    save.min_a = save.min;
    save.max_a = save.max;
    save.min = INT_MAX;
    save.max = INT_MIN;
    while (b)
    {
        if (b->number < save.min)
            save.min = b->number;
        if (b->number > save.max)
            save.max = b->number;
        b = b->next;
    }
    save.min_b = save.min;
    save.max_b = save.max;
    return (save);
}
void step_one(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int if_true;
    int pivot;
    int index;
    int calcul;

    index = 0;
    if_true = 1;
    tmp = *a;
    pivot = search_for_pivot(*a, &calcul);
    *a = tmp;
    while (tmp && index < calcul)
    {
        if (tmp->number > pivot)
        {
            index = 0;
            if_true = 1;
            push(&(*b), &tmp);
        }
        else
        {
            if (if_true == 1)
            {
                calcul = calcul_for_reverse(tmp);
                if_true = 0;
            }
            reverse(&tmp);
            index++;
        }
    }
    *a = tmp;
    print(*a, *b);
}

void step_two(t_stack **a, t_stack **b)
{
    t_save save;
    t_tmp tmp;
    int min;
    int max;
    t_tools tool;

    tmp = init_tmp(*a, *b);
    save = search_for_minmax(tmp.a, tmp.b);
    tmp = init_tmp(*a, *b);
    min = search_for_min(save, tmp.b);
    max = search_for_max(save, tmp.a);
    tmp = init_tmp(*a, *b);
    tmp = init_tmp(*a, *b);
    tool.len_a = count_len_stack(tmp.a);
    tool.len_b = count_len_stack(tmp.b);
    tool.med_a = tool.len_a/2;
    tool.med_b = tool.len_b/2;
    if(tool.len_a % 2 != 0)
        tool.med_a++;
    if(tool.len_b % 2 != 0)
        tool.med_b++;
    tmp = init_tmp(*a, *b);
    tool.diff_a = count_to_number(tmp.a, 1) - tool.med_a; 
    tool.diff_b = count_to_number(tmp.b, 7) - tool.med_b; 
    // while (tmp.a || tmp.b)
    // {
        
    // }
}
/* ============================ tani test ============================ */