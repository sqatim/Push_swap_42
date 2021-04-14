/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:27:05 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 14:21:19 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
*/

static void	push_less_pivot(t_stack **a, t_stack **b, int len)
{
	int		min;
	int		count;
	int		i;
	int		number;

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
				reverse(&(*a), "ra");
			push(&(*b), &(*a), "pb");
			i++;
		}
		else if (count > len / number)
		{
			while ((*a)->number != min)
				reverse_reverse(&(*a), "rra");
			push(&(*b), &(*a), "pb");
			i++;
		}
	}
}

void	logic2(t_stack **a, t_stack **b, int len)
{
	push_less_pivot(&(*a), &(*b), len);
	if ((*b)->next && (*b)->number < (*b)->next->number)
		swap(&(*b), "sb");
	logic1(&(*a));
	push(&(*a), &(*b), "pa");
	if(len == 5)
	push(&(*a), &(*b), "pa");
}
