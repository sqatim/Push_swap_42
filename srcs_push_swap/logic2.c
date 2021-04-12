/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:27:05 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/12 18:37:05 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void logic2(t_stack **a, t_stack **b, t_stack *stack,int len)
{
    int check;
    t_stack *tmp;
    int pivot;
    int min;
    int count;
    int i;

    i = 0;
    tmp = change_element(stack);
    while(i < len / 2)
    {
        tmp = tmp->next;
        i++;
    }
    pivot = tmp->number;
    i = 0;
    while (i < 2)
    {
        len = count_len_stack(*a);
        min = minimum(*a);
        count = count_to_number(*a, min);
        if (count <= len/2)
        {
            while ((*a)->number != min)
                reverse(&(*a), "ra");
            // print(*a, *b);
            push(&(*b), &(*a), "pb");
            i++;
        }
        else if (count > len /2)
        {
            
            while ((*a)->number != min)
                reverse_reverse(&(*a), "rra");
            push(&(*b), &(*a), "pb");
            i++;
        }
    //  pivot = (*a)->next->number;
    }
    if ((*b)->number < (*b)->next->number)
        swap(&(*b), "sb");
    logic1(&(*a));
    push(&(*a), &(*b), "pa");
    push(&(*a), &(*b), "pa");
    // print(*a, *b);
}
// min = minimum(*a);
// min =  maximum(*a);
// if ((*b)->number < pivot)
// {
//     if ((*b)->number < min)
//         push(&(*a), &(*b), "pa");
//     else if ((*b)->number > (*a)->number)
//     {
//         if (check != 1)
//         {
//             rreverse(&(*a), &(*b), "rr");
//             check = 0;
//         }
//         while((*b)->number > (*a)->number)
//             reverse(&(*a), "ra");
//         push(&(*a), &(*b), "pa");
//         // push(&(*a), &(*b), "pa");
//         reverse_reverse(&(*a), "rra");
//     }
// }
// else if ((*b)->number > pivot)
// {
//     if ((*b)->number > max)
//         push(&(*a), &(*b), "pa");
//     else
//     {
//         reverse(&(*a), "ra");
//         push(&(*a), &(*b), "pa");
//     }
// }