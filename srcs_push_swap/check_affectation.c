/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_affectation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:25:46 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 23:33:40 by ragegodthor      ###   ########.fr       */
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
            free_tab(&tab);
            ft_putendl_fd("Error", 2);
            return (0);
        }
        index++;
    }
    return (1);
}

void check_for_duplicates(t_stack *a, t_stack *stack)
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
                free_stack(&stack);
                ft_putendl_fd("Error", 2);
                exit(1);
            }
            check = check->next;
        }
        tmp = tmp->next;
    }
}

int check_arg(char *str)
{
    int i;

    i = 1;
    if (str[0] != '-')
        return (-1);
    if (!str[i + 1])
    {
        if (str[i] == 's')
            return (SHOW);
        if (str[i] == 'c')
            return (COLOR);
    }
    return (-1);
}

t_stack *check_affec(int ac, char **av, t_stack *a, t_stack **stack)
{
    int index;
    char *str;
    char **tab;
    int arg;
    char *tmp;

    index = 1;
    str = ft_strdup("\0");
    arg = check_arg(av[1]);
    if (arg != -1)
        index++;
    while (av[index])
    {
        tmp = str;
        str = ft_strjoin(str, av[index]);
        free(tmp);
        tmp = str;
        str = ft_strjoin(str, " ");
        free(tmp);
        index++;
    }
    tab = ft_space_split(str);
    free(str);
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
    free_tab(&tab);
    check_for_duplicates(a, *stack);
    return (a);
}