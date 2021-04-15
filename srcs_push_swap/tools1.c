/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:36:06 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 16:36:24 by sqatim           ###   ########.fr       */
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
