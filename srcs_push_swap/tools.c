/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:13:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 16:36:26 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_len_stack(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	stack = tmp;
	return (len);
}

int	count_len_pivot(t_pivot *pivot)
{
	int		len;
	t_pivot	*tmp;

	len = 0;
	tmp = pivot;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	count_to_number(t_stack *stack, int number)
{
	int		counter;
	t_stack	*tmp;

	counter = 1;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number == number)
			return (counter);
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int	maximum(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number >= max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

int	minimum(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number <= min)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}
