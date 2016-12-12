/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:38:01 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/08 11:39:42 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_nb(int n)
{
	char	*str;

	if (n >= 0)
		str = (char *)malloc(sizeof(char) * (ft_nblen(n) + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_nblen(n) + 2));
	if (str == NULL)
		return (NULL);
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*s1;
	int		i;
	int		f;

	if (n == 0 || n == -2147483648)
		return (n == 0 ? ft_strdup("0") : ft_strdup("-2147483648"));
	i = 0;
	f = n > 0 ? 1 : -1;
	if ((str = ft_alloc_nb(n)) == NULL)
		return (NULL);
	n = ft_abs(n);
	while (n)
	{
		str[i++] = ((n % 10) + '0');
		n = n / 10;
	}
	if (f == -1)
		str[i++] = '-';
	str[i] = '\0';
	s1 = ft_strrev(str);
	free(str);
	return (s1);
}
