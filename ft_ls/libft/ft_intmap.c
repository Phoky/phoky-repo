/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 09:35:31 by rcolleau          #+#    #+#             */
/*   Updated: 2017/03/03 09:35:38 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intmap(char *str, int c)
{
	int		*tbl;
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(str, c);
	tbl = (int *)malloc(sizeof(int) * ft_tbllen(split));
	if (str == NULL)
		return (0);
	while (*split)
	{
		tbl[i] = ft_atoi(*split);
		i++;
		split++;
	}
	return (tbl);
}
