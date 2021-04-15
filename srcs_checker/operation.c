/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:34:44 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/15 14:32:57 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack **stack, int arg)
{
	t_stack	*tmp;

	if (!(*stack) && arg == DEBUGGER)
		ft_putendl_fd("stack is empty", 1);
	else if (*stack)
	{
		if ((*stack)->next)
		{
			tmp = (*stack);
			(*stack) = (*stack)->next;
			tmp->next = (*stack)->next;
			if (tmp->next && tmp->next->previous)
				tmp->next->previous = tmp;
			(*stack)->previous = NULL;
			(*stack)->next = tmp;
		}
		else if (!(*stack)->next && arg == DEBUGGER)
			ft_putendl_fd("you need at least 2 number in the stack", 1);
	}
}

void	reverse(t_stack **stack, int arg)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) && arg == DEBUGGER)
		ft_putendl_fd("stack is empty", 1);
	else if (*stack)
	{
		if ((*stack)->next)
		{
			tmp = (*stack);
			*stack = (*stack)->next;
			(*stack)->previous = NULL;
			last = *stack;
			while (last->next)
				last = last->next;
			tmp->next = NULL;
			tmp->previous = last;
			last->next = tmp;
		}
		else if (!(*stack)->next && arg == DEBUGGER)
			ft_putendl_fd("you need at least 2 number in the stack", 1);
	}
}

void	push(t_stack **first, t_stack **second, int arg)
{
	t_stack	*new;
	t_stack	*tmp;

	tmp = NULL;
	if (*second == NULL && arg == DEBUGGER)
		ft_putendl_fd("Second Tab is empty", 1);
	else if (*second)
	{
		new = create_node((*second)->number);
		if (*first)
		{
			new->next = *first;
			(*first)->previous = new;
		}
		*first = new;
		if ((*second)->next)
			tmp = (*second)->next;
		free(*second);
		*second = NULL;
		if (tmp)
			*second = tmp;
	}
}

void	reverse_reverse(t_stack **stack, int arg)
{
	t_stack	*tmp;

	if (!(*stack) && arg == DEBUGGER)
		ft_putendl_fd("stack is empty", 1);
	else if (*stack)
	{
		if ((*stack)->next)
		{
			tmp = *stack;
			while (tmp->next)
				tmp = tmp->next;
			(*stack)->previous = tmp;
			tmp->next = *stack;
			tmp->previous->next = NULL;
			tmp->previous = NULL;
			*stack = tmp;
		}
		else if (!(*stack)->next && arg == DEBUGGER)
			ft_putendl_fd("you need at least 2 number in the stack", 1);
	}
}
