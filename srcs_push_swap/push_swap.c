/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:10:51 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/03/29 18:24:41 by sqatim           ###   ########.fr       */
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
    if (b)
        return (0);
    return (1);
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;
    t_stack *tmp_b;
    int total;

    a = NULL;
    b = NULL;
    total = 0;
    int index = 0;
    a = check_affec(ac, av, a);
    tmp = a;
    while (a)
    {
        total += a->number;
        a = a->next;
    }
    total /= 2;
    a = tmp;
    while (!(check_tri(a, b)))
    {
        getchar();
        if (a && a->number <= total)
        {
            while (a && a->number <= total)
            {
                push(&b, &a);
            }
        }
        tmp_b = b;
        while (b)
        {
            if (b->number > index)
                index = b->number;
            b = b->next;
        }
        b = tmp_b;
        print(a, b);
        // while (b->number != index)
            // b = b->next;
        // b = b->previous;
        print(a, b);
        getchar();

        while(b->number != index)
            {
                getchar();
                print(a, b);
                printf("=====================   reverse ===================\n");

                reverse(&b);
                    print(a, b);
                getchar();
            }
        print(a, b);
        push(&a,&b);
        getchar();
        print(a, b);
    }
    a = tmp;
    // free_2_stack(&a, &b);
    return (0);
}