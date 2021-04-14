/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:35:50 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 16:29:27 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int number)
{
    t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    new->next = NULL;
    new->number = number;
    new->previous = NULL;
    return (new);
}

t_stack *allocation(t_stack *stack_a, int nbr)
{
    t_stack *tmp;
    t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    new->number = nbr;
    new->next = NULL;
    new->previous = NULL;
    if (stack_a == NULL)
        return (new);
    tmp = stack_a;
    while (tmp->next)
        tmp = tmp->next;
    new->previous = tmp;
    tmp->next = new;
    return (stack_a);
}

t_pivot	*select_pivot(t_pivot *pivot, int number)
{
	t_pivot	*new;
	t_pivot	*tmp;

	new = (t_pivot *)malloc(sizeof(t_pivot));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->previous = NULL;
	new->pivot = number;
	if (!pivot)
		return (new);
	tmp = pivot;
	while (tmp->next)
		tmp = tmp->next;
	new->previous = tmp;
	tmp->next = new;
	return (pivot);
}