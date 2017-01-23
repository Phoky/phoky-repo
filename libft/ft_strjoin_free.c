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
	char	*s;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(s = (char *)malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	ft_strdel(&s1);
	return (s);
}
