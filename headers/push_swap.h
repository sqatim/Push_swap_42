/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:27:45 by sqatim            #+#    #+#             */
/*   Updated: 2021/03/27 13:03:14 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_stack
{
    int number;
    struct s_stack *next;
    struct s_stack *previous;
    struct s_stack *first;
    struct s_stack *last;
} t_stack;

#endif