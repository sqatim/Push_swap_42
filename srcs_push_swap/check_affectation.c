/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_affectation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:25:46 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/09 00:10:28 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_int(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' && ft_isdigit(str[i + 1]))
        i += 2;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    return (1);
}
int check_for_errors(char **av)
{
    int index;
    int i;
    index = 1;

    while (av[index])
    {
        if (!(check_if_int(av[index])))
        {
            ft_putendl_fd("Error", 2);
            return (0);
        }
        index++;
    }
    return (1);
}

void check_for_duplicates(t_stack *a)
{
    t_stack *tmp;
    t_stack *check;

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

t_stack *check_affec(int ac, char **av, t_stack *a)
{
    int count;
    int index;

    count = 2;
    index = 1;
    if (!check_for_errors(av))
        exit(1);
    if (ac > 2)
    {
        while (count <= ac)
        {
            a = allocation(a, ft_atoi(av[index++]));
            count++;
        }
    }
    else
    {
        ft_putendl_fd("Error", 2);
        exit(1);
    }
    check_for_duplicates(a);
    return (a);
}