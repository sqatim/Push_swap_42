/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:38:17 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/15 23:44:46 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chose_operation(t_stack **stack1, t_stack *stack2, t_tools tool, char c)
{
	static int	check;

	if (tool.if_true == 1)
		check = check_operation(*stack1, tool.max);
	if (check == REVERSE)
	{
		if (c == 'a')
			reverse(&(*stack1), stack2, "ra", tool.arg);
		else
			reverse(&(*stack1), stack2, "rb", tool.arg);
	}
	else if (check == REVERSE_REVERSE)
	{
		if (c == 'a')
			reverse_reverse(&(*stack1), stack2, "rra", tool.arg);
		else
			reverse_reverse(&(*stack1), stack2, "rrb", tool.arg);
	}
}

t_stack	*change_element(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*change;
	int		number;

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

int	select_denominator(int len)
{
	if (len >= 25 && len < 50)
		return (3);
	else if (len >= 50 && len <= 499)
		return (5);
	else
		return (12);
}

static void	step_tree_extended(t_tmp *tmp, t_tools *tool)
{
	t_stack *tmp_b;

	while (tmp->a->number != tool->min)
	{
		tmp_b = tmp->b;
		tool->max = maximum(tmp_b);
		tmp_b = tmp->b;
		while (tmp_b)
		{
			if (tmp_b->number == tool->max && tmp_b->number >= tool->min)
				tool->max = tmp_b->number;
			tmp_b = tmp_b->next;
		}
		if (tmp->b->number == tool->max)
		{
			push(&tmp->a, &tmp->b, "pa", tool->arg);
			tool->if_true = 1;
		}
		else
		{
			chose_operation(&tmp->b, tmp->a, *tool, 'b');
			tool->if_true = 0;
		}
	}
}

void	step_tree(t_stack **a, t_stack **b, t_pivot *pivot, int arg)
{
	t_tmp	tmp;
	t_tools	tool;

	tool.if_true = 1;
	tool.arg = arg;
	tmp = init_tmp(*a, *b);
	while (pivot->next)
		pivot = pivot->next;
	pivot = pivot->previous;
	while (tmp.b)
	{
		tmp = init_tmp(*a, *b);
		if (pivot)
			tool.min = pivot->pivot - 1;
		else
			tool.min = minimum(tmp.b);
		step_tree_extended(&tmp, &tool);
		if (pivot)
			pivot = pivot->previous;
		*b = tmp.b;
		*a = tmp.a;
	}
}
