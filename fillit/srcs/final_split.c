/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:55:59 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/13 13:56:07 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			***final_split(char **tbl)
{
	char	***tf;
	int		i;

	i = 0;
	tf = NULL;
	if ((tf = (char ***)malloc(sizeof(char **) * (ft_tbllen(tbl) + 1))) == NULL)
		return (NULL);
	while (i < ft_tbllen(tbl))
	{
		tf[i] = ft_strsplit(tbl[i], '\n');
		i++;
	}
	tf[ft_tbllen(tbl)] = NULL;
	return (tf);
}
