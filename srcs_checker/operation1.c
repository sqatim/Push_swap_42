/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:31:55 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 14:32:51 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sswap(t_stack **a, t_stack **b, int arg)
{
	swap(&(*a), arg);
	swap(&(*b), arg);
}

void	rreverse(t_stack **a, t_stack **b, int arg)
{
	reverse(&(*a), arg);
	reverse(&(*b), arg);
}

void	rreverse_reverse(t_stack **a, t_stack **b, int arg)
{
	reverse_reverse(&(*a), arg);
	reverse_reverse(&(*b), arg);
}
