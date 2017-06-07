/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:22:27 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/23 16:22:29 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*s_end;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(s_end = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	*(s_end + i + j) = '\0';
	while (j--)
		*(s_end + i + j) = *(s2 + j);
	while (i--)
		*(s_end + i) = *(s1 + i);
	ft_strdel(&s1);
	return (s_end);
}
