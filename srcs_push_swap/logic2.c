/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/07 12:38:21 by sqatim           ###   ########.fr       */
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
    while(stack)
    {
        if(stack->number > save.min_a)
            puts("here");
        stack = stack->next;
    }
}
int search_for_max(int save, t_stack *stack)
{
    while(stack)
    {
        
    }
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

    tmp = init_tmp(*a, *b);    
    save = search_for_minmax(tmp.a, tmp.b);
    tmp = init_tmp(*a, *b);    
    while (tmp.a || tmp.b)
    {

    }
}
/* ============================ tani test ============================ */