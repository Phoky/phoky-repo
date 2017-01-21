/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bck_trck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:06:33 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/21 11:45:56 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		bck_trck(char ***tetra, char **tab, int j)
{
	int i;
	int k;

	i = 0;
	if (!tetra[j])
		return (1);
	while (tab[i])
	{
		k = 0;
		while (tab[i][k])
		{
			if (cmp_tetri_tab(tetra[j], tab, i, k) == 1)
			{
				tetri_on(tab, tetra[j], i, k);
				if (bck_trck(tetra, tab, j + 1) == 1)
					return (1);
				tetri_off(tab, tetra[j], i, k);
			}
			k++;
		}
		i++;
	}
	return (0);
}
