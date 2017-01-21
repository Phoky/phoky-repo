/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:33:04 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/15 14:46:08 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**crea_tab(int size)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		j = 0;
		res[i] = (char *)malloc(sizeof(char) * size);
		while (j < size)
		{
			res[i][j] = '.';
			j++;
		}
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}
