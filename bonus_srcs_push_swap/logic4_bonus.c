/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:45:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 00:20:36 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	chose_operation(t_stack **stack, int number, int if_true, char c)
{
	static int	check;

	if (if_true == 1)
		check = check_operation(*stack, number);
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

t_pivot	*select_pivot(t_pivot *pivot, int number)
{
	t_pivot	*new;
	t_pivot	*tmp;

	new = (t_pivot *)malloc(sizeof(t_pivot));
	if (!new)
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
	int		if_true;
	int		max;
	int		min;

	if_true = 1;
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
}

static void	step_tree(t_stack **a, t_stack **b, t_pivot *pivot)
{
	t_tmp	tmp;
	t_stack	*tmp_b;
	int		if_true;
	int		max;
	int		min;

	if_true = 1;
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

void	logic4(t_stack **a, t_stack **b, t_stack *stack, int len)
{
	t_pivot	*pivot;

	pivot = NULL;
	pivot = step_zero(stack, len);
	step_one(&(*a), &(*b), pivot);
	step_two(&(*a), &(*b));
	step_tree(&(*a), &(*b), pivot);
}
