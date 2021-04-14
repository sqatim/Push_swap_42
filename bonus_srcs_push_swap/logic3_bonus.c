/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:22:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 00:20:31 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* 
**  step one    :   I push from the smallest to the largest from stack 'A' To 'B'
**  step two    :   I push all element to stack 'A'
*/

void	chose_operation1(t_stack **stack, int numb, int if_true)
{
	t_stack		*tmp;
	t_tools		tool;
	static int	check;

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
		reverse(&(*stack), "ra");
	else if (check == REVERSE_REVERSE)
		reverse_reverse(&(*stack), "rra");
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

void	push_or_operation(t_stack **a, t_stack **b, int pivot, int *if_true)
{
	int	number;

	number = select_number(*a, pivot);
	if ((*a)->number <= pivot && (*a)->number == number)
	{
		push(&(*b), &(*a), "pb");
		*if_true = 1;
	}
	else
	{
		chose_operation1(&(*a), number, *if_true);
		*if_true = 0;
	}
}

void	step_one(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	int		if_true;
	int		pivot;
	int		calcul;

	if_true = 1;
	while (*a)
	{
		tmp_a = *a;
		pivot = search_for_pivot(tmp_a, &calcul);
		while (*a)
		{
			push_or_operation(&(*a), &(*b), pivot, &if_true);
			if (*b && (*b)->number == pivot)
				break ;
		}
	}
}

void	logic3(t_stack **a, t_stack **b)
{
	step_one(&(*a), &(*b));
	while (*b)
		push(&(*a), &(*b), "pa");
}
