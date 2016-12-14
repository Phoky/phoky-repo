/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:14:34 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/04 14:37:53 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	i;
	int	*tbl;

	i = min;
	tbl = malloc(sizeof(int) * ((max - min) + 1));
	while (min < max)
	{
		tbl[i] = (min);
		i++;
		min++;
	}
	return (tbl);
}
