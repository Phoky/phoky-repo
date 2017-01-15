/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bck_trck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:06:33 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/14 17:52:13 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		bck_trck(char **tetra, char **tab, int i, int j)
{
	if (cmp_tetri_tab(tetra, tab, i, j) == 1)
	{
		tetri_on(tab, tetra, i, j);
		if (bck_trck((char **)(tetra + 1), tab, i, j) == 1)
			return (1);
		tetri_off(tab, tetra, i, j);
	}
	else if (tab[i][j + 1])
		bck_trck(tetra, tab, i, j + 1);
	else if (tab[i + 1])
		bck_trck(tetra, tab, i + 1, 0);
	return (0);
}
