/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:36:43 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/03/28 12:57:29 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void instruction(char **buffer, t_stack **a, t_stack **b)
{
    if (!(ft_strncmp(*buffer, "pa\n", 3)))
        push(&(*a), &(*b));
    else if (!(ft_strncmp(*buffer, "pb\n", 3)))
        push(&(*b), &(*a));
    else if (!(ft_strncmp(*buffer, "ra\n", 3)))
        reverse(&(*a));
    else if (!(ft_strncmp(*buffer, "rb\n", 3)))
        reverse(&(*b));
    else if (!(ft_strncmp(*buffer, "rr\n", 3)))
        rreverse(&(*a), &(*b));
    else if (!(ft_strncmp(*buffer, "rra\n", 4)))
        reverse_reverse(&(*a));
    else if (!(ft_strncmp(*buffer, "rrb\n", 4)))
        reverse_reverse(&(*b));
    else if (!(ft_strncmp(*buffer, "rrr\n", 4)))
        rreverse_reverse(&(*a), &(*b));
    else
    {
        free_string(&(*buffer));
        free_2_stack(&(*a), &(*b));
        ft_putendl_fd("Error", 2);
        exit(1);
    }
}
void read_instructions(t_stack **a, t_stack **b)
{
    char *buffer;

    while (1)
    {
        buffer = (char *)ft_calloc(10, 1);
        read(0, buffer, 10);

        if (!(ft_strncmp(buffer, "\0", 1)))
        {
            free_string(&buffer);
            break;
        }
        else if ((!(ft_strncmp(buffer, "\n", 1))))
        {
            free_string(&buffer);
            continue;
        }
        else if (!(ft_strncmp(buffer, "sa\n", 3)))
            swap(&(*a));
        else if (!(ft_strncmp(buffer, "sb\n", 3)))
            swap(&(*b));
        else if (!(ft_strncmp(buffer, "ss\n", 3)))
            sswap(&(*a), &(*b));
        else
            instruction(&buffer, &(*a), &(*b));
        print(*a, *b);
        free_string(&buffer);
    }
}
