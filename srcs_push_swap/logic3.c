/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/12 15:31:48 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ============================ tani test ============================ */

// je push au stack b le min au max et le repusher to a

/* ============================   pause   ============================ */
int which_operation1(t_stack *a, t_stack *b, t_tools tool)
{
	// printf("%d\n", tool.count_b - tool.count_a);
	if(tool.diff_a <= 0)
		return (REVERSE_A);
	else if(tool.diff_a > 0)
		return (REVERSE_REVERSE_A);
	else if (tool.diff_a <= 0 && tool.diff_b <= 0)
	{
		puts("==== 1 ====");
		return (RREVERSE);
	}
	else if (tool.diff_a <= 0 && tool.diff_b > 0 && (tool.count_b - tool.count_a) - tool.med_b <= tool.diff_b)
	{
		puts("==== 2 ====");
		return (RREVERSE);
	}
	else if (tool.diff_b <= 0 && tool.diff_a > 0 && (tool.count_a - tool.count_b) - tool.med_a < tool.diff_a)
	{
		puts("==== 3 ====");
		return (RREVERSE);
	}
	else if (tool.diff_a > 0 && tool.diff_b > 0)
	{
		puts("==== 3 ====");
		return (RREVERSE_REVERSE);
	}
	else if (tool.diff_a > 0 && tool.diff_b <= 0 && (tool.count_b + tool.count_a) - tool.med_b >= tool.diff_b)
	{
		puts("==== 4 ====");
		return (RREVERSE_REVERSE);
	}
	else if (tool.diff_b > 0 && tool.diff_a <= 0 && (tool.count_a + tool.count_b) - tool.med_a > tool.diff_a)
	{
		puts("==== 5 ====");
		return (RREVERSE_REVERSE);
	}
	return (5000);
}

// int search_for_min(t_save save, t_stack *stack)
// {
//     int min;

//     min = save.max_b;
//     while (stack)
//     {
//         if (stack->number <= min && stack->number >= save.min_b && stack->number <= save.max_b)
//             min = stack->number;
//         stack = stack->next;
//     }
//     return (min);
// }
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

void chose_operation1(t_tmp *tmp, int numb, int if_true)
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
        check = which_operation1(tmp->a, tmp->b, tool);
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

    tmp = init_tmp(*a, *b);
    while (tmp.a)
    {
        tmp = init_tmp(*a, *b);
        pivot = search_for_pivot(tmp.a, &calcul);
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
            {
                push(&tmp.b, &tmp.a, "pb");
                if_true = 1;
            }
            else
            {
                chose_operation1(&tmp, numb, if_true);
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

void step_two(t_stack **a, t_stack **b)
{
    int counter = 0;
    while (*b)
    {
        counter++;
        push(&(*a), &(*b), "pa");
    }
    // printf("counter ==> %d\n", counter);
}
/* ============================ tani test ============================ */

void logic3(t_stack **a, t_stack **b, t_stack *stack, int len)
{
    step_one(&(*a), &(*b));
    step_two(&(*a), &(*b));
}