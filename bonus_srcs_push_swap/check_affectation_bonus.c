/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_affectation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:25:46 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 00:19:46 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
    if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
        return (0);
    return (1);
}

int check_for_errors(char **tab)
{
    int index;

    index = 0;
    while (tab[index])
    {
        if (!(check_if_int(tab[index])))
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

t_stack *check_affec(int ac, char **av, t_stack *a, t_stack **stack)
{
    int index;
    char *str;
    char **tab;

    index = 1;
    str = ft_strdup("\0");
    while (av[index])
    {
        str = ft_strjoin(str, av[index]);
        str = ft_strjoin(str, " ");
        index++;
    }
    tab = ft_space_split(str);
    if (!check_for_errors(tab))
        exit(1);
    index = 0;
    if (ac > 1)
    {
        while (tab[index])
        {
            a = allocation(a, ft_atoi(tab[index]));
            *stack = allocation(*stack, ft_atoi(tab[index]));
            index++;
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