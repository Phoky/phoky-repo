/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:33:07 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/01 18:17:29 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*s1;
	int		i;
	int		j;

	i = (ft_strlen(str) - 1);
	j = 0;
	if (*str == 0)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * i);
	if (s1 == NULL)
		return (NULL);
	while (i >= 0)
		s1[j++] = str[i--];
	s1[j] = '\0';
	return (s1);
}
