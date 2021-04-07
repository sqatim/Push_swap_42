/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:10:51 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/07 12:31:21 by sqatim           ###   ########.fr       */
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