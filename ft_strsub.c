/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:00:04 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/30 21:21:36 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	if (ft_strlen(s) < (start + len) || (char *)s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (i == start)
		{
			j = 0;
			while (j < len)
				str[j++] = *(char *)(s + i++);
		}
		i++;
	}
	return (str);
}
