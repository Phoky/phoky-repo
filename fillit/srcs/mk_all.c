/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:14:43 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/14 17:46:24 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**mk_all(char ***tetri)
{
	int		flag;
	char	**tabf;
	int		i;

	flag = 0;
	i = 2;
	while (flag == 0)
	{
		tabf = crea_tab(i);
		if (bck_trck(tetri[0], tabf, 0, 0) == 1)
			flag++;
		i++;
	}
	return (tabf);
}
