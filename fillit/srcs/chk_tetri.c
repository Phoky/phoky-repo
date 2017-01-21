/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_r_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:22:03 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/15 12:18:58 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_tetri(char **tetri, int i, int lg_tetri, int flag)
{
	int	j;

	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] != '.')
			{
				lg_tetri++;
				if (tetri[i][j + 1] && tetri[i][j + 1] != '.')
					flag++;
				if (tetri[i + 1] && tetri[i + 1][j] && tetri[i + 1][j] != '.')
					flag++;
			}
			j++;
		}
		i++;
	}
	if (lg_tetri == 4 && flag > 2)
		return (1);
	return (0);
}

int			chk_tetri(char **tetri)
{
	int i;
	int lg_tetri;
	int flag;

	i = 0;
	flag = 0;
	lg_tetri = 0;
	if ((check_tetri(tetri, i, lg_tetri, flag)) == 1)
		return (1);
	return (0);
}
