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
	char	*s;
	size_t	l;

	l = (ft_strlen(s1) + len);
	if (!(s = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	ft_strcpy(s, s1);
	ft_strncat(s, s2, len);
	ft_strdel(&s1);
	return (s);
}
