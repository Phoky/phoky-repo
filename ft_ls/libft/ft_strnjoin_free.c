/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:55:00 by rcolleau          #+#    #+#             */
/*   Updated: 2017/02/04 17:56:50 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, char const *s2, size_t len)
{
	char	*s_end;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	if (!(s_end = (char *)malloc(sizeof(char) * (i + len + 1))))
		return (NULL);
	*(s_end + i + len) = '\0';
	while (len--)
		*(s_end + i + len) = *(s2 + len);
	while (i--)
		*(s_end + i) = *(s1 + i);
	ft_strdel(&s1);
	return (s_end);
}
