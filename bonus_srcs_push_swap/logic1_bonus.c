/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:52:25 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/14 00:20:15 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	logic1(t_stack **a)
{
	if ((*a)->number > (*a)->next->number && (*a)->next->number <\
		(*a)->next->next->number && (*a)->number < (*a)->next->next->number)
		swap(&(*a), "sa");
	else if ((*a)->number < (*a)->next->number && (*a)->next->number \
		> (*a)->next->next->number && (*a)->number < (*a)->next->next->number)
	{
		swap(&(*a), "sa");
		reverse(&(*a), "ra");
	}
	else if ((*a)->number > (*a)->next->number && (*a)->next->number
		> (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
	{
		swap(&(*a), "sa");
		reverse_reverse(&(*a), "rra");
	}
	else if ((*a)->number > (*a)->next->number && (*a)->next->number \
		< (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
		reverse(&(*a), "ra");
	else if ((*a)->number < (*a)->next->number && (*a)->next->number \
		> (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
		reverse_reverse(&(*a), "rra");
}
