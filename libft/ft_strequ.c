/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:17:14 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/12 14:34:34 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			while (s1[i] == s2[i])
			{
				i++;
				if (s1[i] == '\0' && s2[i] == '\0')
					return (1);
			}
		}
		if (s1[i] != s2[i] || s2[i] == '\0')
			return (0);
	}
	return (0);
}
