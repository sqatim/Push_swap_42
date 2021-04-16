/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/16 13:42:22 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 **  step zero   :   search pivots
 **  step one    :   push to stack 'B' elements
 **						less the pivot ( except the last part )
 **  step two    :   sort the last part which is
 **						in the stack 'A' and push it to stack 'B'
 **  step tree   :   push the last part to stack 'A' ;
 **					 	sort stack 'B' and push to 'A'
 */

static t_pivot	*step_zero(t_stack *a, int len)
{
	t_stack	*tmp;
	t_pivot	*pivot;
	int		counter;
	int		i;
	int		denominator;

	counter = 0;
	i = 1;
	pivot = NULL;
	tmp = change_element(a);
	denominator = select_denominator(len);
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

static void	step_one(t_stack **a, t_stack **b, t_pivot *pivot, int arg)
{
	t_tmp	tmp;
	t_tools	tool;
	int		index;

	index = 0;
	tool.count = minimum(*a);
	tool.len = count_len_pivot(pivot);
	while (index < tool.len)
	{
		tmp = init_tmp(*a, *b);
		while (tool.count <= pivot->pivot)
		{
			if (tmp.a->number <= pivot->pivot)
			{
				push(&tmp.b, &tmp.a, "pb", arg);
				tool.count++;
			}
			else
				reverse(&tmp.a, tmp.b, "ra", arg);
		}
		pivot = pivot->next;
		index++;
		*b = tmp.b;
		*a = tmp.a;
	}
}

static void	step_two_extended(t_tmp *tmp, t_tools *tool, int arg)
{
	t_stack	*tmp_a;

	tmp_a = tmp->a;
	tool->max = maximum(tmp->a);
	while (tmp_a)
	{
		if (tmp_a->number <= tool->max)
			tool->max = tmp_a->number;
		tmp_a = tmp_a->next;
	}
	if (tmp->a->number == tool->max)
	{
		push(&tmp->b, &tmp->a, "pb", arg);
		tool->if_true = 1;
	}
	else
	{
		chose_operation(&tmp->a, tmp->b, *tool, 'a');
		tool->if_true = 0;
	}
}

static void	step_two(t_stack **a, t_stack **b, int arg)
{
	t_tmp	tmp;
	t_tools	tool;

	tool.if_true = 1;
	tool.arg = arg;
	tmp = init_tmp(*a, *b);
	tool.min = minimum(tmp.a);
	while (tmp.a)
		step_two_extended(&tmp, &tool, arg);
	*b = tmp.b;
	*a = tmp.a;
	while ((*b)->number >= tool.min)
		push(&(*a), &(*b), "pa", arg);
}

void	logic4(t_stack **a, t_stack **b, t_stack *stack, int arg)
{
	t_pivot	*pivot;
	int		len;

	len = count_len_stack(*a);
	pivot = NULL;
	pivot = step_zero(stack, len);
	step_one(&(*a), &(*b), pivot, arg);
	step_two(&(*a), &(*b), arg);
	step_tree(&(*a), &(*b), pivot, arg);
	free_pivot(&pivot);
}
