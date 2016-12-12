/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:57:47 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/12 14:29:15 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ordo(const char *s, int c)
{
	int	comp;

	comp = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			comp++;
			while (*s != c)
				s++;
		}
		s++;
	}
	return (comp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		m;
	int		n;
	int		o;
	char	**tbl;

	if (s == NULL)
		return (NULL);
	i = 0;
	o = 0;
	n = ft_strlen(s);
	if ((tbl = (char **)malloc(sizeof(char*) * (ft_ordo(s, c) + 1))) == NULL)
		return (NULL);
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
	tbl[o] = NULL;
	return (tbl);
}
