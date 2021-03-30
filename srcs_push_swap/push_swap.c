/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:10:51 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/03/30 18:15:44 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_tri(t_stack *a, t_stack *b)
{
    while (a && a->next)
    {
        if (a->number > a->next->number || b)
            return (0);
        a = a->next;
    }
    // if (b)
    //     return (0);
    return (1);
}

int search_for_pivot(t_stack *a, int *calcul)
{
    int pivot;
    int counter;

    counter = 0;
    pivot = 0;
    while (a)
    {
        pivot += a->number;
        a = a->next;
        counter++;
    }
    *calcul = counter;
    pivot /= counter;
    return (pivot);
}
int calcul_for_reverse(t_stack *a)
{
    int counter;

    counter = 0;
    while (a)
    {
        counter++;
        a = a->next;
    }
    return (counter);
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
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;
    t_stack *tmp_b;

    a = NULL;
    b = NULL;
    a = check_affec(ac, av, a);
    tmp = a;
    if (!(check_tri(a, b)))
    {
        a = tmp;
        step_one(&a, &b);
        step_two(&a, &b);
    }
    a = tmp;

    a = tmp;
    // free_2_stack(&a, &b);
    return (0);
}