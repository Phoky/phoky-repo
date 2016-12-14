/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:42:54 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/12 19:14:08 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (big == NULL && DO_SEGFAULT == 1)
		*(volatile int *)0 = 0;
	else if (big == NULL)
		return (NULL);
	i = ft_strlen(little);
	while (n >= i && *big != '\0')
	{
		if (ft_strncmp(big, little, i) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}
