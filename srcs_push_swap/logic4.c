/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 17:17:46 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 **  step zero   :   search pivots
 **  step one    :   push to stack 'B' elements 
 						less the pivot ( except the last part )
 **  step two    :   sort the last part which is 
 						in the stack 'A' and push it to stack 'B'
 **  step tree   :   push the last part to stack 'A' ;
 					 	sort stack 'B' and push to 'A'
 */

static int	check_operation(t_stack *stack, int number)
{
	t_stack	*tmp;
	int		check;
	t_tools	tool;

	tmp = stack;
	tool.len = count_len_stack(tmp);
	tool.med = tool.len / 2;
	if (tool.len % 2 != 0)
		tool.med++;
	tmp = stack;
	tool.count = count_to_number(tmp, number);
	tool.diff = tool.count - tool.med;
	check = which_operation(tool.diff);
	return (check);
}

void	chose_operation(t_stack **stack, t_tools tool, char c)
{
	static int	check;

	if (tool.if_true == 1)
		check = check_operation(*stack, tool.max);
	if (check == REVERSE)
	{
		if (c == 'a')
			reverse(&(*stack), "ra");
		else
			reverse(&(*stack), "rb");
	}
	else if (check == REVERSE_REVERSE)
	{
		if (c == 'a')
			reverse_reverse(&(*stack), "rra");
		else
			reverse_reverse(&(*stack), "rrb");
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

static void	step_one(t_stack **a, t_stack **b, t_pivot *pivot)
{
	t_tmp	tmp;
	int		counter;
	int		index;
	int		len;

	index = 0;
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

static void	step_two(t_stack **a, t_stack **b)
{
	t_tmp	tmp;
	t_stack	*tmp_a;
	t_tools tool;

	tool.if_true = 1;
	tmp = init_tmp(*a, *b);
	tool.min = minimum(tmp.a);
	while (tmp.a)
	{
		tmp_a = tmp.a;
		tool.max = maximum(tmp.a);
		while (tmp_a)
		{
			if (tmp_a->number <= tool.max)
				tool.max = tmp_a->number;
			tmp_a = tmp_a->next;
		}
		if (tmp.a->number == tool.max)
		{
			push(&tmp.b, &tmp.a, "pb");
			tool.if_true = 1;
		}
		else
		{
			chose_operation(&tmp.a, tool, 'a');
			tool.if_true = 0;
		}
	}
	*b = tmp.b;
	*a = tmp.a;
	while ((*b)->number >= tool.min)
		push(&(*a), &(*b), "pa");
}

static void	step_tree(t_stack **a, t_stack **b, t_pivot *pivot)
{
	t_tmp	tmp;
	t_stack	*tmp_b;
	t_tools tool;

	tool.if_true = 1;
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
		while (tmp.a->number != tool.min)
		{
			tmp_b = tmp.b;
			tool.max = maximum(tmp_b);
			tmp_b = tmp.b;
			while (tmp_b)
			{
				if (tmp_b->number == tool.max && tmp_b->number >= tool.min)
					tool.max = tmp_b->number;
				tmp_b = tmp_b->next;
			}
			if (tmp.b->number == tool.max)
			{
				push(&tmp.a, &tmp.b, "pa");
				tool.if_true = 1;
			}
			else
			{
				chose_operation(&tmp.b, tool, 'b');
				tool.if_true = 0;
			}
		}
		if (pivot)
			pivot = pivot->previous;
		*b = tmp.b;
		*a = tmp.a;
	}
}

void	logic4(t_stack **a, t_stack **b, t_stack *stack, int arg)
{
	t_pivot	*pivot;
	int len;

	len = count_len_stack(*a);
	pivot = NULL;
	pivot = step_zero(stack, len);
	step_one(&(*a), &(*b), pivot);
	step_two(&(*a), &(*b));
	step_tree(&(*a), &(*b), pivot);
}
