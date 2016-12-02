/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:55:37 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/01 18:34:11 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	while (i < n)
	{
		a = ((char *)s1)[i];
		b = ((char *)s2)[i];
		if (((char *)s1)[i] < 0 || ((char *)s1)[i] > 127)
			a = -((char *)s1)[i];
		if (((char *)s2)[i] < 0 || ((char *)s2)[i] > 127)
			b = -((char *)s2)[i];
		if (((char *)s1)[i] == ((char *)s2)[i])
			i++;
		else
			return (a - b);
	}
	return (0);
}
