/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 22:31:27 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
**  step one    :   I push from the smallest to the largest from stack 'A' To 'B'
**  step two    :   I push all element to stack 'A'
*/

void	chose_operation1(t_stack **stack1, t_stack *stack2, int numb, t_tools tool)
{
	t_stack		*tmp;
	static int	check;

	if (tool.if_true == 1)
	{
		tmp = *stack1;
		tool.len = count_len_stack(tmp);
		tool.med = tool.len / 2;
		if (tool.len % 2 != 0)
			tool.med++;
		tmp = *stack1;
		tool.count = count_to_number(tmp, numb);
		tool.diff = tool.count - tool.med;
		check = which_operation(tool.diff);
	}
	if (check == REVERSE)
		reverse(&(*stack1), stack2, "ra", tool.arg);
	else if (check == REVERSE_REVERSE)
		reverse_reverse(&(*stack1), stack2, "rra", tool.arg);
}

int	select_number(t_stack *a, int pivot)
{
	int		number;
	t_stack	*tmp_a;

	tmp_a = a;
	number = pivot;
	while (tmp_a)
	{
		if (tmp_a->number < number)
			number = tmp_a->number;
		tmp_a = tmp_a->next;
	}
	return (number);
}

void	push_or_operation(t_stack **a, t_stack **b, t_tools *tool, int arg)
{
	int	number;

	tool->arg = arg;
	number = select_number(*a, tool->pivot);
	if ((*a)->number <= tool->pivot && (*a)->number == number)
	{
		push(&(*b), &(*a), "pb", arg);
		tool->if_true = 1;
	}
	else
	{
		chose_operation1(&(*a), *b ,number, *tool);
		tool->if_true = 0;
	}
}

void	step_one(t_stack **a, t_stack **b, int arg)
{
	t_stack	*tmp_a;
	t_tools tool;
	int		calcul;

	tool.if_true = 1;
	while (*a)
	{
		tmp_a = *a;
		tool.pivot = search_for_pivot(tmp_a, &calcul);
		while (*a)
		{
			push_or_operation(&(*a), &(*b), &tool, arg);
			if (*b && (*b)->number == tool.pivot)
				break ;
		}
	}
}

void	logic3(t_stack **a, t_stack **b, int arg)
{
	step_one(&(*a), &(*b), arg);
	while (*b)
		push(&(*a), &(*b), "pa", arg);
}
