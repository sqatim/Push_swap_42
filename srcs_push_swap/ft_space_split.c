/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:15:11 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/15 23:21:44 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (j);
}

static void	*leak(char **spl, int j)
{
	j = j - 1;
	while (spl[j])
	{
		free(spl[j]);
		j--;
	}
	free(spl);
	return (NULL);
}

static int	carcts(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		i++;
	}
	return (i);
}

static char	*alloc(char **tab, char *src)
{
	int			i;
	int			j;
	int			o;

	j = 0;
	o = 0;
	while (src[o] == ' ' || src[o] == '\t')
		o++;
	while (j < words(src))
	{
		i = 0;
		tab[j] = malloc(sizeof(char) * (carcts(&src[o]) + 1));
		if (!tab[j])
			return (leak(tab, j));
		while ((src[o] != '\t' && src[o] != ' ') && src[o])
		{
			tab[j][i++] = src[o++];
		}
		tab[j][i] = '\0';
		while ((src[o] == '\t' || src[o] == ' ') && src[o])
			o++;
		j++;
	}
	tab[j] = NULL;
	return (*tab);
}

char	**ft_space_split(char const *s)
{
	int			j;
	char		**tab;
	char		*str;

	j = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (words(str) + 1));
	if (!tab)
		return (NULL);
	tab[j] = alloc(tab, str);
	return (tab);
}
