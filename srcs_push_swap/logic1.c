/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:52:25 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 22:46:53 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logic1(t_stack **a, t_stack *b, int arg)
{
	if ((*a)->number > (*a)->next->number && (*a)->next->number <\
		(*a)->next->next->number && (*a)->number < (*a)->next->next->number)
		swap(&(*a), b, "sa", arg);
	else if ((*a)->number < (*a)->next->number && (*a)->next->number \
		> (*a)->next->next->number && (*a)->number < (*a)->next->next->number)
	{
		swap(&(*a), b, "sa", arg);
		reverse(&(*a), b, "ra", arg);
	}
	else if ((*a)->number > (*a)->next->number && (*a)->next->number
		> (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
	{
		swap(&(*a), b, "sa", arg);
		reverse_reverse(&(*a), b, "rra", arg);
	}
	else if ((*a)->number > (*a)->next->number && (*a)->next->number \
		< (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
		reverse(&(*a), b, "ra", arg);
	else if ((*a)->number < (*a)->next->number && (*a)->next->number \
		> (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
		reverse_reverse(&(*a), b, "rra", arg);
}
