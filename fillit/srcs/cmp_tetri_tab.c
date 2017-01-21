/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_tetri_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:06:02 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/21 12:12:48 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	cmp_tetri_tab(char **tetri, char **tab, int li, int col)
{
	int i;
	int j;
	int flag;

	flag = 1;
	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (!tab[li + i] && tetri[i][j] != '.')
				return (0);
			else if (tetri[i][j] != '.' && tab[li + i] && !tab[li + i][col + j])
				return (0);
			else if (tetri[i][j] != '.' && tab[li + i] && tab[li + i][col + j]
					&& tab[li + i][col + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (flag);
}
