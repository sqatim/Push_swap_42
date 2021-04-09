/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/09 17:06:01 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* ============================ tani test ============================ */

// je push au stack b le min au max et le repusher to a

/* ============================   play   ============================ */

t_tmp init_tmp(t_stack *a, t_stack *b)
{
    t_tmp tmp;

    tmp.a = a;
    tmp.b = b;
    return (tmp);
}

void chose_operation(t_tmp *tmp, int numb, int if_true)
{
    t_stack *tmp_a;
    t_tools tool;
    static int check;

    if (if_true == 1)
    {
        tmp_a = tmp->a;
        tool.len_a = count_len_stack(tmp_a);
        tool.med_a = tool.len_a / 2;
        if (tool.len_a % 2 != 0)
            tool.med_a++;
        tmp_a = tmp->a;
        tool.count_a = count_to_number(tmp_a, numb);
        tool.diff_a = tool.count_a - tool.med_a;
        check = which_operation(tmp->a, tmp->b, tool);
    }
    if (check == REVERSE_A)
    {
        // puts("===== REVERSE_A =====");
        reverse(&tmp->a, "ra");
        // print(tmp->a, tmp->b);
    }
    else if (check == REVERSE_REVERSE_A)
    {
        // puts("===== REVERSE_REVERSE_A =====");
        reverse_reverse(&tmp->a, "rra");
        // print(tmp->a, tmp->b);
    }
}

void step_one(t_stack **a, t_stack **b)
{
    t_tmp tmp;
    t_stack *tmp_a;
    int if_true = 1;
    int pivot;
    int index;
    int calcul;
    int numb;
    int check;
    t_save save;
    t_tools tool;
    t_bef_pivot *b_pivot;

    b_pivot = NULL;
    tmp = init_tmp(*a, *b);
    while (tmp.a)
    {
        tmp = init_tmp(*a, *b);
        pivot = search_for_pivot(tmp.a, &calcul);
        tmp = init_tmp(*a, *b);
        while (tmp.a)
        {
            tmp_a = tmp.a;
            if (tmp.a->number <= pivot)
            {
                push(&tmp.b, &tmp.a, "pb");
                if_true = 1;
            }
            else
            {
                chose_operation(&tmp, numb, if_true);
                if_true = 0;
            }
            if (tmp.b && tmp.b->number == pivot)
                break;
        }
        *b = tmp.b;
        *a = tmp.a;
    }
    // print(*a, *b);
}