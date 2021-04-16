/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:10:51 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/16 13:41:18 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_approx(t_stack *a, int pivot)
{
	int	number;

	number = INT_MAX;
	while (a)
	{
		if (a->number == pivot)
			return (pivot);
		if (abs(a->number - pivot) < number)
			number = a->number;
		a = a->next;
	}
	return (number);
}

int	search_for_pivot(t_stack *a, int *calcul)
{
	int		pivot;
	int		counter;
	t_stack	*tmp;

	counter = 0;
	pivot = 0;
	tmp = a;
	while (a)
	{
		pivot += a->number;
		a = a->next;
		counter++;
	}
	a = tmp;
	*calcul = counter;
	pivot /= counter;
	pivot = pivot_approx(a, pivot);
	return (pivot);
}

int	calcul_for_reverse(t_stack *a)
{
	int	counter;

	counter = 0;
	while (a)
	{
		counter++;
		a = a->next;
	}
	return (counter);
}

void	which_logic(t_stack **a, t_stack **b, t_stack *stack, int arg)
{
	int	len;

	len = count_len_stack(*a);
	if (len == 2)
		swap(&(*a), *b, "sa", arg);
	else if (len == 3)
		logic1(&(*a), *b, arg);
	else if (len <= 5)
		logic2(&(*a), &(*b), len, arg);
	else if (len < 25)
		logic3(&(*a), &(*b), arg);
	else if (len >= 25)
		logic4(&(*a), &(*b), stack, arg);
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*a;
	t_stack	*b;
	int		arg;

	stack = NULL;
	a = NULL;
	b = NULL;
	a = check_affec(ac, av, a, &stack);
	arg = check_arg(av[1]);
	if (!(check_sort(a, b)))
		which_logic(&a, &b, stack, arg);
	free_stack(&stack);
	free_stack(&a);
	return (0);
}
