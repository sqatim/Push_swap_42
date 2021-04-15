/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:27:05 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 22:29:19 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
*/

static void	push_less_pivot_extended(t_stack **a, t_stack **b, \
				t_tools tool, int *i)
{
	tool.len = count_len_stack(*a);
	tool.min = minimum(*a);
	tool.count = count_to_number(*a, tool.min);
	if (tool.count <= tool.len / tool.number)
	{
		while ((*a)->number != tool.min)
			reverse(&(*a), *b, "ra", tool.arg);
		push(&(*b), &(*a), "pb", tool.arg);
		(*i)++;
	}
	else if (tool.count > tool.len / tool.number)
	{
		while ((*a)->number != tool.min)
			reverse_reverse(&(*a), *b, "rra", tool.arg);
		push(&(*b), &(*a), "pb", tool.arg);
		(*i)++;
	}
}

static void	push_less_pivot(t_stack **a, t_stack **b, int len, int arg)
{
	int		i;
	int		number;
	t_tools	tool;

	i = 0;
	tool.len = len;
	number = 1;
	if (len == 5)
		number = 2;
	tool.arg = arg;
	tool.number = number;
	while (i < number)
		push_less_pivot_extended(&(*a), &(*b), tool, &i);
}

void	logic2(t_stack **a, t_stack **b, int len, int arg)
{
	push_less_pivot(&(*a), &(*b), len, arg);
	if ((*b)->next && (*b)->number < (*b)->next->number)
		swap(&(*b), *a, "sb", arg);
	logic1(&(*a), *b, arg);
	push(&(*a), &(*b), "pa", arg);
	if (len == 5)
		push(&(*a), &(*b), "pa", arg);
}
