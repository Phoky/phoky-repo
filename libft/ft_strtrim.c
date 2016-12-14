/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:03:03 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/14 20:07:59 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	c;

	j = 0;
	c = 0;
	if (s == NULL)
		return (NULL);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	if (s[j] == '\0')
		return (ft_strdup(""));
	if ((str = (char *)malloc(sizeof(char) * ((i - j) + 2))) == NULL)
		return (NULL);
	while (j <= i)
		str[c++] = ((char *)s)[j++];
	str[c] = '\0';
	return (str);
}
