/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:05:07 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/16 15:26:33 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_if_sort(t_stack **a, t_stack **b, int arg)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number || *b)
		{
			if (*b && arg == DEBUGGER)
				ft_putendl_fd("Stack 'B' Not Empty", 1);
			free_2_stack(&(*a), &(*b));
			ft_putendl_fd("\033[1;31mKO\033[0m", 1);
			exit(1);
		}
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		arg;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		a = check_affec(ac, av, a, &arg);
		read_instructions(&a, &b, arg);
		check_if_sort(&a, &b, arg);
		free_2_stack(&a, &b);
		ft_putendl_fd("\033[1;32mOK\033[0m", 1);
	}
	return (0);
}
