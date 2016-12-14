/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:33:07 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/08 11:16:05 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*s1;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (*str == 0)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * (i + 1));
	if (s1 == NULL)
		return (NULL);
	while (i > 0)
		s1[j++] = str[--i];
	s1[j] = '\0';
	return (s1);
}
