/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_affectation1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:58:33 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 14:59:49 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_for_duplicates(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*check;

	tmp = a;
	while (tmp->next)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->number == check->number)
			{
				free_stack(&a);
				ft_putendl_fd("Error", 2);
				exit(1);
			}
			check = check->next;
		}
		tmp = tmp->next;
	}
}

int	check_if_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		i += 2;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}
