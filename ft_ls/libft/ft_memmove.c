/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:58:10 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/14 14:38:37 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = ((unsigned char *)dst);
	s = ((unsigned char *)src);
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
