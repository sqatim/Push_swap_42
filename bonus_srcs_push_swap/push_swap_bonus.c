/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:10:51 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 00:20:54 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
    t_stack *stack;
    t_stack *a;
    t_stack *b;
    int len;

    stack = NULL;
    a = NULL;
    b = NULL;
    a = check_affec(ac, av, a, &stack);

    if (!(check_tri(a, b)))
    {
        len = count_len_stack(a);
        if (len == 2)
            swap(&a, "sa");
        else if (len == 3)
            logic1(&a);
        else if (len <= 5)
            logic2(&a, &b, len);
        else if (len < 25)
            logic3(&a, &b);
        else if (len >= 25)
            logic4(&a, &b, stack, len);
    }
    // a = tmp;
    // print(a, b);
    // free_2_stack(&a, &b);
    return (0);
}