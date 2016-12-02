/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:18:05 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/30 19:23:05 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < n || ((char *)dst)[i] == c)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((char *)src)[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
