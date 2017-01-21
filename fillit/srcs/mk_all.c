/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:14:43 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/21 11:45:50 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**mk_all(char ***tetri, int sz_min)
{
	int		flag;
	char	**tabf;
	int		i;

	flag = 0;
	i = 1;
	while (sz_min > i * i)
		i++;
	while (flag == 0)
	{
		tabf = crea_tab(i);
		if (bck_trck(tetri, tabf, 0) == 1)
			flag++;
		i++;
	}
	return (tabf);
}
