/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:57:47 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/30 18:04:31 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ordo(const char *s, int c)
{
	int	comp;

	comp = 0;
	while (*s != '\0')
	{
		if (*s != c)
			comp++;
		s++;
	}
	return (comp);
}

int		ft_part(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_ptr(char *dest, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * n);
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		m;
	int		n;
	int		o;
	char	**tbl;

	i = 0;
	o = 0;
	n = ft_strlen(s);
	tbl = (char **)malloc(sizeof(*tbl) * (ft_ordo(s, c)));
	while (i < n)
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			m = ft_part((s + i), c);
			tbl[o] = ft_ptr(tbl[o], (s + i), m);
			o++;
			i = i + m;
		}
	}
	return (tbl);
}
