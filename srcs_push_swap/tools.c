/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:13:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/07 23:25:26 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_len_stack(t_stack *stack)
{
	int len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int count_to_number(t_stack *stack, int number)
{
	int counter;

	counter = 1;
	while (stack)
	{
		if (stack->number == number)
			return (counter);
		counter++;
		stack = stack->next;
	}
	return (counter);
}

int which_operation(t_stack *a, t_stack *b, t_tools tool)
{
	if (tool.diff_a <= 0 && tool.diff_b <= 0)
		return (RREVERSE);
	else if (tool.diff_a <= 0 && tool.diff_b > 0 && (tool.count_b - tool.count_a) < tool.diff_b)
		return (RREVERSE);
	else if (tool.diff_b <= 0 && tool.diff_a > 0 && (tool.count_a - tool.count_b) < tool.diff_a)
		return (RREVERSE);
	else if (tool.diff_a > 0 && tool.diff_b > 0)
		return (RREVERSE_REVERSE);
	else if (tool.diff_a > 0 && tool.diff_b <= 0 && (tool.count_b + tool.count_a) > tool.diff_b)
		return (RREVERSE_REVERSE);
	else if (tool.diff_b > 0 && tool.diff_a <= 0 && (tool.count_a + tool.count_b) > tool.diff_a)
		return (RREVERSE_REVERSE);
	return (0);
}