/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:42:54 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/12 15:00:09 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (big == NULL)
		return (ft_strtrim(big+12));
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
