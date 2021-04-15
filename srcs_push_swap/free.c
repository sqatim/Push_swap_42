/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:41:36 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/15 15:37:45 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = tmp;
	}
}

void	free_2_stack(t_stack **a, t_stack **b)
{
	if (*a)
		free_stack(&(*a));
	if (*b)
		free_stack(&(*b));
}

void	free_tab(char ***tab)
{
	int	index;

	index = 0;
	if (*tab != NULL && *tab[index] != NULL)
	{
		while ((*tab)[index])
		{
			free((*tab)[index]);
			(*tab)[index] = NULL;
			index++;
		}
		free(*tab);
		*tab = NULL;
	}
}

void	free_pivot(t_pivot **pivot)
{
	t_pivot	*tmp;

	while (*pivot)
	{
		tmp = (*pivot)->next;
		free(*pivot);
		*pivot = NULL;
		*pivot = tmp;
	}
}
