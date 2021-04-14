/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:27:55 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 00:20:48 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void print(t_stack *a, t_stack *b)
{
    t_stack *tmp_a = a;
    t_stack *tmp_b = b;

    printf("|            a            |            b            |\n");
    printf("|---------------------------------------------------|\n");

    while (tmp_a || tmp_b)
    {
        if (tmp_a && tmp_b)
            printf("|            %d            |            %d            |\n", tmp_a->number, tmp_b->number);
        else if (!tmp_a && tmp_b)
            printf("|                         |            %d            |\n", tmp_b->number);
        else if (tmp_a && !tmp_b)
            printf("|            %d            |                         |\n", tmp_a->number);
        if (tmp_a)
            tmp_a = tmp_a->next;
        if (tmp_b)
            tmp_b = tmp_b->next;
    }
}
