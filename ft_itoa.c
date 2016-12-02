/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:48:06 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/02 14:57:20 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memnb(int n)
{
	char *str;

	if (n > 0)
		str = ft_memalloc(n);
	else if (n == 0)
		str = ft_memalloc(1);
	else if (n < 0)
		str = ft_memalloc(n + 1);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		f;

	f = 0;
	i = ft_nblen(n);
	if (n < 0)
	{
		f = 1;
		n = -n;
	}
	str = ft_memnb(i);
	i = 0;
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		str = "8463847412-";
	else if (n == 0)
		str = "0";
	while (n)
	{
		str[i++] = ((n % 10) + '0');
		n = n / 10;
	}
	if (f == 1)
		str[i] = '-';
	return (ft_strrev(str));
}
