/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:41:48 by sqatim            #+#    #+#             */
/*   Updated: 2021/04/16 13:54:16 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if ((!s) || (unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (ft_strdup(""));
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
