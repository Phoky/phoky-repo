/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:32:08 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/11 12:32:26 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
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
	return (s_end);
}
