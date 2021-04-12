/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/12 18:11:48 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ============================ tani test ============================ */

// je push au stack b le min au max et le repusher to a

/* ============================   play   ============================ */



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
        if (c == 'a')
            reverse(&(*stack), "ra"); //ra
        else
            reverse(&(*stack), "rb");
    }
    else if (check == REVERSE_REVERSE)
    {
        if (c == 'a')
            reverse_reverse(&(*stack), "rra"); //ra
        else
            reverse_reverse(&(*stack), "rrb");
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
t_stack *change_element(t_stack *a)
{
    t_stack *tmp;
    t_stack *change;
    int number;

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
    return (a);
}
static t_pivot *step_zero(t_stack *a, int len)
{
    t_stack *tmp;
    t_pivot *pivot;
    int counter;
    int i;
    int denominator;

    counter = 0;
    i = 1;
    pivot = NULL;
    tmp = change_element(a);
    // 500 => 10
    if (len >= 25 && len < 50)
        denominator = 3;
    else if (len >= 50 && len <= 499)
        denominator = 5;
    else if (len > 499)
        denominator = 12;
    while (tmp && i < denominator)
    {
        if ((i * (len / denominator)) == counter)
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

static void step_one(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_tmp tmp;
    int counter = 0;
    int index = 0;
    int len;

    counter = minimum(*a);
    len = count_len_pivot(pivot);
    while (index < len)
    {
        tmp = init_tmp(*a, *b);
        while (counter <= pivot->pivot)
        {
            if (tmp.a->number <= pivot->pivot)
            {
                push(&tmp.b, &tmp.a, "pb");
                counter++;
            }
            else
                reverse(&tmp.a, "ra");
        }
        pivot = pivot->next;
        index++;
        *b = tmp.b;
        *a = tmp.a;
    }
}

// i pushed to stack b the last elements but sorted and take back it to stack a

static void step_two(t_stack **a, t_stack **b, t_pivot *pivot)
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
            if_true = 0;
        }
    }
    *b = tmp.b;
    *a = tmp.a;
    while ((*b)->number >= min)
        push(&(*a), &(*b), "pa");
    // print(*a, *b);
}

static void step_tree(t_stack **a, t_stack **b, t_pivot *pivot)
{
    t_tmp tmp;
    t_stack *tmp_b;
    int if_true = 1;
    int max;
    int min;

    tmp = init_tmp(*a, *b);
    while (pivot->next)
        pivot = pivot->next;
    pivot = pivot->previous;
    while (tmp.b)
    {
        tmp = init_tmp(*a, *b);
        if (pivot)
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
                if_true = 0;
            }
        }
        if (pivot)
            pivot = pivot->previous;
        *b = tmp.b;
        *a = tmp.a;
    }
}

void logic4(t_stack **a, t_stack **b, t_stack *stack, int len)
{
    t_pivot *pivot;

    pivot = NULL;
    pivot = step_zero(stack, len);
    step_one(&(*a), &(*b), pivot);
    step_two(&(*a), &(*b), pivot);
    step_tree(&(*a), &(*b), pivot);
}
