/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:41:36 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 00:17:54 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void free_string(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = tmp;
	}
}

void free_2_stack(t_stack **a, t_stack **b)
{
	if (*a)
		free_stack(&(*a));
	if (*b)
		free_stack(&(*b));
}