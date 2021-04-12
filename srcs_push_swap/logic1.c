/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:52:25 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/12 18:32:21 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void logic1(t_stack **a)
{
    if((*a)->number > (*a)->next->number && (*a)->next->number < (*a)->next->next->number && (*a)->number < (*a)->next->next->number)
        swap(&(*a), "sa");
    else if((*a)->number < (*a)->next->number && (*a)->next->number > (*a)->next->next->number && (*a)->number < (*a)->next->next->number)
    {
        swap(&(*a), "sa");
        reverse(&(*a), "ra");
    }
    else if ((*a)->number > (*a)->next->number && (*a)->next->number > (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
    {
        swap(&(*a), "sa");
        reverse_reverse(&(*a), "rra");
    }
    else if((*a)->number > (*a)->next->number && (*a)->next->number < (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
        reverse(&(*a), "ra");
    else if((*a)->number < (*a)->next->number && (*a)->next->number > (*a)->next->next->number && (*a)->number > (*a)->next->next->number)
        reverse_reverse(&(*a), "rra");
}