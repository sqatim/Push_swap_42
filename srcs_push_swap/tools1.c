/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:36:06 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 23:40:08 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_operation(int diff)
{
	if (diff <= 0)
		return (REVERSE);
	else if (diff > 0)
		return (REVERSE_REVERSE);
	return (-1);
}

t_tmp	init_tmp(t_stack *a, t_stack *b)
{
	t_tmp	tmp;

	tmp.a = a;
	tmp.b = b;
	return (tmp);
}

int	check_sort(t_stack *a, t_stack *b)
{
	while (a && a->next)
	{
		if (a->number > a->next->number || b)
			return (0);
		a = a->next;
	}
	if (b)
		return (0);
	return (1);
}

int	check_operation(t_stack *stack, int number)
{
	t_stack	*tmp;
	int		check;
	t_tools	tool;

	tmp = stack;
	tool.len = count_len_stack(tmp);
	tool.med = tool.len / 2;
	if (tool.len % 2 != 0)
		tool.med++;
	tmp = stack;
	tool.count = count_to_number(tmp, number);
	tool.diff = tool.count - tool.med;
	check = which_operation(tool.diff);
	return (check);
}
