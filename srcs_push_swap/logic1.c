/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/08 18:15:35 by sqatim           ###   ########.fr       */
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

int search_for_min(t_save save, t_stack *stack)
{
    int min;

    min = save.max_b;
    while (stack)
    {
        if (stack->number <= min && stack->number >= save.min_b && stack->number <= save.max_b)
            min = stack->number;
        stack = stack->next;
    }
    return (min);
}
int search_for_max(t_save save, t_stack *stack)
{
    int max;

    max = save.min_a;
    while (stack)
    {
        if (stack->number >= max && stack->number >= save.min_a && stack->number <= save.max_a)
            max = stack->number;
        stack = stack->next;
    }
    return (max);
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
    if (b)
    {
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
    }
    return (save);
}
void step_one(t_stack **a, t_stack **b)
{
    t_tmp tmp;
    t_stack *tmp_a;
    int if_true;
    int pivot;
    int index;
    int calcul;
    int numb;
    int check;
    t_save save;
    t_tools tool;

    index = 0;
    if_true = 1;
    tmp = init_tmp(*a, *b);
    pivot = search_for_pivot(*a, &calcul);
    *a = tmp.a;
    save = search_for_minmax(tmp.a, tmp.b);
    tmp = init_tmp(*a, *b);
    while (tmp.a)
    {
        tmp_a = tmp.a;
        numb = pivot;
        while (tmp_a)
        {
            if (tmp_a->number < numb)
                numb = tmp_a->number;
            tmp_a = tmp_a->next;
        }
        if (tmp.a->number <= pivot && tmp.a->number == numb)
            push(&(*b), &tmp.a);
        else
        {
            tmp_a = tmp.a;
            tool.len_a = count_len_stack(tmp_a);
            tool.med_a = tool.len_a / 2;
            if (tool.len_a % 2 != 0)
                tool.med_a++;
            tmp_a = tmp.a;
            tool.count_a = count_to_number(tmp_a, numb);
            tool.diff_a = tool.count_a - tool.med_a;
            check = which_operation(tmp.a, tmp.b, tool);
            if (check == REVERSE_A)
            {
                puts("===== REVERSE_A =====");
                reverse(&tmp.a);
                print(tmp.a, *b);
            }
            else if (check == REVERSE_REVERSE_A)
            {
                puts("===== REVERSE_REVERSE_A =====");
                reverse_reverse(&tmp.a);
                print(tmp.a, *b);
            }
        }
        printf("pivot ==> %d\n",pivot);
        if (*b && (*b)->number == pivot)
            break;
    }
    *a = tmp.a;
    print(*a, *b);
}

void step_two(t_stack **a, t_stack **b)
{
    t_save save;
    t_tmp tmp;
    int min;
    int max;
    t_tools tool;
    int operation;
    int check;
    int i = 0;

    tmp = init_tmp(*a, *b);
    save = search_for_minmax(tmp.a, tmp.b);
    tmp = init_tmp(*a, *b);
    tmp = init_tmp(*a, *b);
    tmp = init_tmp(*a, *b);
    tool.len_a = count_len_stack(tmp.a);
    tool.len_b = count_len_stack(tmp.b);
    tool.med_a = tool.len_a / 2;
    tool.med_b = tool.len_b / 2;
    if (tool.len_a % 2 != 0)
        tool.med_a++;
    if (tool.len_b % 2 != 0)
        tool.med_b++;
    tmp = init_tmp(*a, *b);
    while (tmp.a || tmp.b)
    {
        min = search_for_min(save, tmp.b);
        max = search_for_max(save, tmp.a);
        tmp = init_tmp(*a, *b);
        tool.count_a = count_to_number(tmp.a, max);
        tool.count_b = count_to_number(tmp.b, min);
        printf("max ==> %d|\t|min ==> %d|\n", max, min);
        tool.diff_a = tool.count_a - tool.med_a;
        tool.diff_b = tool.count_b - tool.med_b;
        getchar();
        printf("|count.a ==> %d|\t|med.a ==> |%d|\t|diff_a ==> {%d}\n", tool.count_a, tool.med_a, tool.diff_a);
        printf("|count.b ==> %d|\t|med.b ==> |%d|\t|diff_b ==> {%d}\n", tool.count_b, tool.med_b, tool.diff_b);
        tmp = init_tmp(*a, *b);
        check = which_operation(tmp.a, tmp.b, tool);
        printf("check ==> {%d}\n", check);
        getchar();
        if (check == RREVERSE)
        {
            while (tmp.a->number != max && tmp.b->number != min)
                rreverse(&tmp.a, &tmp.b);
            printf("*********************************\n");
            print(tmp.a, tmp.b);
            printf("*********************************\n");
            while (tmp.a->number != max)
                reverse(&tmp.a);
            while (tmp.b->number != min)
                reverse(&tmp.b);
            printf("######################################\n");
            print(tmp.a, tmp.b);
            printf("######################################\n");
            push(&tmp.a, &tmp.b);
            reverse(&tmp.a);
            push(&tmp.b, &tmp.a);
            reverse(&tmp.b);
            print(tmp.a, tmp.b);
            printf("{i ==> %d}\n", i++);
        }
        *a = tmp.a;
        *b = tmp.b;
    }
}
/* ============================ tani test ============================ */