/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:36:43 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/14 15:52:01 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void instruction(char **buffer, t_stack **a, t_stack **b)
{
    if (!(ft_strncmp(*buffer, "pa\0", 3)))
        push(&(*a), &(*b));
    else if (!(ft_strncmp(*buffer, "pb\0", 3)))
        push(&(*b), &(*a));
    else if (!(ft_strncmp(*buffer, "ra\0", 3)))
        reverse(&(*a));
    else if (!(ft_strncmp(*buffer, "rb\0", 3)))
        reverse(&(*b));
    else if (!(ft_strncmp(*buffer, "rr\0", 3)))
        rreverse(&(*a), &(*b));
    else if (!(ft_strncmp(*buffer, "rra\0", 4)))
        reverse_reverse(&(*a));
    else if (!(ft_strncmp(*buffer, "rrb\0", 4)))
        reverse_reverse(&(*b));
    else if (!(ft_strncmp(*buffer, "rrr\0", 4)))
        rreverse_reverse(&(*a), &(*b));
    else
        // {
        //     free_string(&(*buffer));
        //     free_2_stack(&(*a), &(*b));
        ft_putendl_fd("Error", 2);
    // exit(1);
    // }
}
void read_instructions(t_stack **a, t_stack **b, int arg)
{
    char *buffer;

    while (get_next_line(0, &buffer))
    {
        if(arg == DEBUGGER)
        system("clear");
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
        else if (!(ft_strncmp(buffer, "sa\0", 3)))
            swap(&(*a));
        else if (!(ft_strncmp(buffer, "sb\0", 3)))
            swap(&(*b));
        else if (!(ft_strncmp(buffer, "ss\0", 3)))
            sswap(&(*a), &(*b));
        else
            instruction(&buffer, &(*a), &(*b));
        if(arg == DEBUGGER)
            print(*a, *b);
        free_string(&buffer);
    }
}
