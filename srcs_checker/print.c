/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:27:55 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/15 14:59:59 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	len_of_element(int number)
{
	int	counter;

	counter = 1;
	if (number < 0)
		counter++;
	number = abs(number);
	if (number < 10)
		return (1);
	while (number >= 10)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

void	print_space(int number, int counter, int end, int present)
{
	int	space;
	int	result;
	int	i;

	i = 0;
	result = 25 - counter;
	space = result / 2;
	printf("|");
	while (i < space)
	{
		printf(" ");
		i++;
	}
	if (present == 1)
		printf("%d", number);
	i = 0;
	space = 25 - space - counter;
	while (i < space)
	{
		printf(" ");
		i++;
	}
	if (end == 1)
		printf("|\n");
}

void	print_extended(t_stack *a, t_stack *b)
{
	int	counter[2];

	if (a)
		counter[0] = len_of_element(a->number);
	if (b)
		counter[1] = len_of_element(b->number);
	if (a && b)
	{
		print_space(a->number, counter[0], 0, 1);
		print_space(b->number, counter[1], 1, 1);
	}
	else if (!a && b)
	{
		print_space(0, 0, 0, 0);
		print_space(b->number, counter[1], 1, 1);
	}
	else if (a && !b)
	{
		print_space(a->number, counter[0], 0, 1);
		print_space(0, 0, 1, 0);
	}
}

void	print(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	printf("|            a            |            b            |\n");
	printf("|---------------------------------------------------|\n");
	while (tmp_a || tmp_b)
	{
		print_extended(tmp_a, tmp_b);
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}
