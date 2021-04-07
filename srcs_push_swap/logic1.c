/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:20:53 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/07 12:22:30 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* ============================ awal test ============================ */
/* ============================   Pause   ============================ */

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
    t_stack *tmp;
    int number;
    int count;
    int index;

    index = 0;
    count = 0;
    tmp = *a;
    number = 0;
    while (tmp)
    {
        number = INT_MAX;
        while (tmp)
        {
            if (tmp->number <= number)
                number = tmp->number;
            tmp = tmp->next;
        }
        tmp = *a;
        while (tmp->number != number)
            reverse(&tmp);
        push(&(*b), &tmp);
        count++;
    }
    *a = tmp;
    while(index < count)
    {
        push(&(*a), &(*b));
        index++;
    }
    print(*a, *b);
}

/* ============================ awal test ============================ */