/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:13:41 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/08 16:48:19 by sqatim           ###   ########.fr       */
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
	// printf("%d\n", tool.count_b - tool.count_a);
	if(tool.diff_a <= 0)
		return (REVERSE_A);
	else if(tool.diff_a > 0)
		return (REVERSE_REVERSE_A);
	else if (tool.diff_a <= 0 && tool.diff_b <= 0)
	{
		puts("==== 1 ====");
		return (RREVERSE);
	}
	else if (tool.diff_a <= 0 && tool.diff_b > 0 && (tool.count_b - tool.count_a) - tool.med_b <= tool.diff_b)
	{
		puts("==== 2 ====");
		return (RREVERSE);
	}
	else if (tool.diff_b <= 0 && tool.diff_a > 0 && (tool.count_a - tool.count_b) - tool.med_a < tool.diff_a)
	{
		puts("==== 3 ====");
		return (RREVERSE);
	}
	else if (tool.diff_a > 0 && tool.diff_b > 0)
	{
		puts("==== 3 ====");
		return (RREVERSE_REVERSE);
	}
	else if (tool.diff_a > 0 && tool.diff_b <= 0 && (tool.count_b + tool.count_a) - tool.med_b >= tool.diff_b)
	{
		puts("==== 4 ====");
		return (RREVERSE_REVERSE);
	}
	else if (tool.diff_b > 0 && tool.diff_a <= 0 && (tool.count_a + tool.count_b) - tool.med_a > tool.diff_a)
	{
		puts("==== 5 ====");
		return (RREVERSE_REVERSE);
	}
	return (5000);
}