/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:27:05 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 00:20:24 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
**
*/

static void	push_less_pivot(t_stack **a, t_stack **b, int len)
{
	int		min;
	int		count;
	int		i;

	i = 0;
	while (i < 2)
	{
		len = count_len_stack(*a);
		min = minimum(*a);
		count = count_to_number(*a, min);
		if (count <= len / 2)
		{
			while ((*a)->number != min)
				reverse(&(*a), "ra");
			push(&(*b), &(*a), "pb");
			i++;
		}
		else if (count > len / 2)
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
	if ((*b)->number < (*b)->next->number)
		swap(&(*b), "sb");
	logic1(&(*a));
	push(&(*a), &(*b), "pa");
	push(&(*a), &(*b), "pa");
}
