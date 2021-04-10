/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/10 20:58:56 by ragegodthor      ###   ########.fr       */
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

// void chose_operation_a(t_tmp *tmp, int numb, int if_true)
// {
//     t_stack *tmp_a;
//     t_tools tool;
//     static int check;

//     if (if_true == 1)
//     {
//         tmp_a = tmp->a;
//         tool.len_a = count_len_stack(tmp_a);
//         tool.med_a = tool.len_a / 2;
//         if (tool.len_a % 2 != 0)
//             tool.med_a++;
//         tmp_a = tmp->a;
//         tool.count_a = count_to_number(tmp_a, numb);
//         tool.diff_a = tool.count_a - tool.med_a;
//         check = which_operation(tmp->a, tmp->b, tool);
//     }
//     if (check == REVERSE_A)
//     {
//         // puts("===== REVERSE_A =====");
//         reverse(&tmp->a, "ra");
//         // print(tmp->a, tmp->b);
//     }
//     else if (check == REVERSE_REVERSE_A)
//     {
//         // puts("===== REVERSE_REVERSE_A =====");
//         reverse_reverse(&tmp->a, "rra");
//         // print(tmp->a, tmp->b);
//     }
// }
// int soso(t_stack *b, t_tools tool)
// {
//     if (tool.diff_b <= 0)
//         return (REVERSE_B);
//     else if (tool.diff_b > 0)
//         return (REVERSE_REVERSE_B);
//     return (5000);
// }
// void chose_operation_b(t_tmp *tmp, int numb, int if_true)
// {
//     t_stack *tmp;
//     t_tools tool;
//     static int check;

//     if (if_true == 1)
//     {
//         tmp = tmp->b;
//         tool.len_b = count_len_stack(tmp);
//         tool.med_b = tool.len_b / 2;
//         if (tool.len_b % 2 != 0)
//             tool.med_b++;
//         tmp = tmp->b;
//         tool.count_b = count_to_number(tmp, numb);
//         tool.diff_b = tool.count_b - tool.med_b;
//         check = soso(tmp->b, tool);
//     }
//     if (check == REVERSE_B)
//     {
//         // puts("===== REVERSE_B =====");
//         reverse(&tmp->b, "rb");
//         // print(tmp->b, tmp->b);
//     }
//     else if (check == REVERSE_REVERSE_B)
//     {
//         // puts("===== REVERSE_REVERSE_B =====");
//         reverse_reverse(&tmp->b, "rrb");
//         // print(tmp->a, tmp->b);
//     }
// }

void chose_operation(t_stack **stack, int numb, int if_true, char c)
{
    t_stack *tmp;
    t_tools tool;
    static int check;

    if (if_true == 1)
    {
        tmp = *stack;
        tool.len = count_len_stack(tmp);
        tool.med = tool.len / 2;
        if (tool.len % 2 != 0)
            tool.med++;
        tmp = *stack;
        tool.count = count_to_number(tmp, numb);
        tool.diff = tool.count - tool.med;
        check = which_operation(tool.diff);
    }
    if (check == REVERSE)
    {
        // puts("===== REVERSE_A =====");
        if (c == 'a')
            reverse(&(*stack), "ra"); //ra
        else
            reverse(&(*stack), "rb");
        // print(tmp->a, tmp->b);
    }
    else if (check == REVERSE_REVERSE)
    {
        // puts("===== REVERSE_REVERSE_A =====");
        if (c == 'a')
            reverse_reverse(&(*stack), "rra"); //ra
        else
            reverse_reverse(&(*stack), "rrb");
        // print(tmp->a, tmp->b);
    }
}

t_pivot *select_pivot(t_pivot *pivot, int number)
{
    t_pivot *new;
    t_pivot *tmp;

    if (!(new = (t_pivot *)malloc(sizeof(t_pivot))))
        return (NULL);
    new->next = NULL;
    new->previous = NULL;
    new->pivot = number;
    if (!pivot)
        return (new);
    tmp = pivot;
    while (tmp->next)
        tmp = tmp->next;
    new->previous = tmp;
    tmp->next = new;
    return (pivot);
}

// je cherche les pivot
t_pivot *step_zero(t_stack *a)
{
    t_stack *tmp;
    t_stack *change;
    t_pivot *pivot;
    pivot = NULL;
    int counter = 0;
    int i = 1;
    int index = 0;
    int number;
    int len;
    tmp = a;
    while (tmp)
    {
        change = tmp->next;
        while (change)
        {
            if (change->number < tmp->number)
            {
                number = tmp->number;
                tmp->number = change->number;
                change->number = number;
            }
            change = change->next;
        }
        tmp = tmp->next;
    }
    tmp = a;
    len = count_len_stack(tmp);
    tmp = a;
    while (tmp && i < 5)
    {
        if ((i * (len / 5)) == counter)
        {
            pivot = select_pivot(pivot, tmp->number);
            i++;
        }
        counter++;
        tmp = tmp->next;
    }
    return (pivot);
}

// je push les element qui sont petit du pivot (sauf les dernier apres le dernier pivot)

void step_one(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_tmp tmp;
    // int if_true = 1;
    int counter = 0;
    int index = 0;
    int len;

    len = count_len_pivot(pivot);
    // printf("pivot ==> %d\n", pivot->pivot);
    // getchar();
    while (index < len)
    {
        tmp = init_tmp(*a, *b);
        while (counter < pivot->pivot)
        {
            if (tmp.a->number <= pivot->pivot)
            {
                // printf("number ==> %d\n", tmp.a->number);
                // getchar();
                push(&tmp.b, &tmp.a, "pb");
                counter++;
            }
            else
            {
                reverse(&tmp.a, "ra");
            }
        }
        pivot = pivot->next;
        index++;
        *b = tmp.b;
        *a = tmp.a;
    }
}

int maximum(t_stack *stack)
{
    int max;
    t_stack *tmp;

    max = INT_MIN;
    tmp = stack;
    while (tmp)
    {
        if (tmp->number >= max)
            max = tmp->number;
        tmp = tmp->next;
    }
    return (max);
}

int minimum(t_stack *stack)
{
    int min;
    t_stack *tmp;

    min = INT_MAX;
    tmp = stack;
    while (tmp)
    {
        if (tmp->number <= min)
            min = tmp->number;
        tmp = tmp->next;
    }
    return (min);
}
// i pushed to stack b the last elements but sorted and take back it to stack a

void step_two(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_tmp tmp;
    t_stack *tmp_a;
    int if_true = 1;
    t_tools tool;
    int max;
    int min;

    tmp = init_tmp(*a, *b);
    min = minimum(tmp.a);
    while (tmp.a)
    {
        tmp_a = tmp.a;
        max = maximum(tmp.a);
        while (tmp_a)
        {
            if (tmp_a->number <= max)
                max = tmp_a->number;
            tmp_a = tmp_a->next;
        }
        if (tmp.a->number == max)
        {
            push(&tmp.b, &tmp.a, "pb");
            if_true = 1;
        }
        else
        {
            chose_operation(&tmp.a, max, if_true, 'a');
            // print(tmp.a, tmp.b);
            // getchar();
            if_true = 0;
        }
    }
    *b = tmp.b;
    *a = tmp.a;
    while ((*b)->number >= min)
        push(&(*a), &(*b), "pa");
}

void step_tree(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_tmp tmp;
    t_stack *tmp_b;
    int if_true = 1;
    t_tools tool;
    int max;
    int min;

    tmp = init_tmp(*a, *b);
    while (pivot->next)
        pivot = pivot->next;
    pivot = pivot->previous;
    while (tmp.b)
    {
        tmp = init_tmp(*a, *b);
        if (pivot->previous)
            min = pivot->pivot - 1;
        else
            min = minimum(tmp.b);
        while (tmp.a->number != min)
        {
            tmp_b = tmp.b;
            max = maximum(tmp_b);
            tmp_b = tmp.b;
            while (tmp_b)
            {
                if (tmp_b->number == max && tmp_b->number >= min)
                    max = tmp_b->number;
                tmp_b = tmp_b->next;
            }
            if (tmp.b->number == max)
            {
                push(&tmp.a, &tmp.b, "pa");
                if_true = 1;
            }
            else
            {
                chose_operation(&tmp.b, max, if_true, 'b');
                // print(tmp.a, tmp.b);
                // getchar();
                if_true = 0;
            }
        }
        if (pivot)
        {
            pivot = pivot->previous;
        }
        *b = tmp.b;
        *a = tmp.a;
    }
    *b = tmp.b;
    *a = tmp.a;
}
