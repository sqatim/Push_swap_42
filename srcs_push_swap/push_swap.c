/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:10:51 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/09 17:06:20 by sqatim           ###   ########.fr       */
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

int pivot_approx(t_stack *a, int pivot)
{
    int number;

    number = INT_MAX;
    while (a)
    {
        if (a->number == pivot)
            return (pivot);
        if (abs(a->number - pivot) < number)
            number = a->number;
        a = a->next;
    }
    return (number);
}
int search_for_pivot(t_stack *a, int *calcul)
{
    int pivot;
    int counter;
    t_stack *tmp;

    counter = 0;
    pivot = 0;
    tmp = a;
    while (a)
    {
        pivot += a->number;
        a = a->next;
        counter++;
    }
    a = tmp;
    *calcul = counter;
    pivot /= counter;
    pivot = pivot_approx(a, pivot);
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
        // step_two(&a, &b);
    }
    // a = tmp;
    print(a, b);
    // free_2_stack(&a, &b);
    return (0);
}