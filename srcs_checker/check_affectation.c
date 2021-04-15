/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_affectation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:25:46 by ragegodthor       #+#    #+#             */
/*   Updated: 2021/04/15 15:00:11 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_for_errors(char **tab)
{
	int	index;

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

int	check_arg(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (-1);
	if (!str[i + 1])
	{
		if (str[i] == 'v')
			return (DEBUGGER);
	}
	return (-1);
}

char	**parse_elements(char **av, int *arg)
{
	char	*str;
	char	*tmp;
	char	**tab;
	int		index;

	index = 1;
	str = ft_strdup("\0");
	*arg = check_arg(av[1]);
	if (*arg != -1)
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
	return (tab);
}

t_stack	*check_affec(int ac, char **av, t_stack *a, int *arg)
{
	int		index;
	char	**tab;

	tab = parse_elements(av, arg);
	if (!check_for_errors(tab))
		exit(1);
	index = 0;
	if (ac > 1)
	{
		while (tab[index])
		{
			a = allocation(a, ft_atoi(tab[index]));
			index++;
		}
	}
	else
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	free_tab(&tab);
	check_for_duplicates(a);
	return (a);
}
