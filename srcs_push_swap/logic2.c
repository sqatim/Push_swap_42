/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:27:05 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 22:21:11 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
*/

static void push_less_pivot(t_stack **a, t_stack **b, int len, int arg)
{
	int min;
	int count;
	int i;
	int number;

	i = 0;
	number = 1;
	if (len == 5)
		number = 2;
	while (i < number)
	{
		len = count_len_stack(*a);
		min = minimum(*a);
		count = count_to_number(*a, min);
		if (count <= len / number)
		{
			while ((*a)->number != min)
				reverse(&(*a), *b, "ra", arg);
			push(&(*b), &(*a), "pb", arg);
			i++;
		}
		else if (count > len / number)
		{
			while ((*a)->number != min)
				reverse_reverse(&(*a), *b, "rra", arg);
			push(&(*b), &(*a), "pb", arg);
			i++;
		}
	}
}

void logic2(t_stack **a, t_stack **b, int len, int arg)
{
	push_less_pivot(&(*a), &(*b), len, arg);
	if ((*b)->next && (*b)->number < (*b)->next->number)
		swap(&(*b), *a, "sb", arg);
	logic1(&(*a), *b, arg);
	push(&(*a), &(*b), "pa", arg);
	if (len == 5)
		push(&(*a), &(*b), "pa", arg);
}
