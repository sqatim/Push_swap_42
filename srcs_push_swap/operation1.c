/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:24:50 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 16:39:31 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_reverse_reverse(t_stack **stack1, t_stack *stack2, \
			char *name, int arg)
{
	if (name)
	{
		if (arg == COLOR)
			ft_putstr_fd(RED, 1);
		ft_putendl_fd(name, 1);
	}
	if (arg == SHOW)
	{
		system("clear");
		if (name[2] == 'a')
			print(*stack1, stack2);
		else
			print(stack2, *stack1);
		sleep(1);
	}
}

void	reverse_reverse(t_stack **stack1, t_stack *stack2, char *name, int arg)
{
	t_stack	*tmp;

	if (!(*stack1))
		ft_putendl_fd("stack is empty", 1);
	else
	{
		if ((*stack1)->next)
		{
			tmp = *stack1;
			while (tmp->next)
				tmp = tmp->next;
			(*stack1)->previous = tmp;
			tmp->next = *stack1;
			tmp->previous->next = NULL;
			tmp->previous = NULL;
			*stack1 = tmp;
			print_reverse_reverse(stack1, stack2, name, arg);
		}
		else
			ft_putendl_fd("you need at least 2 number in the stack", 1);
	}
}
