/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_off.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:58:43 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/16 15:46:52 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetri_off(char **tab, char **tetri, int li, int col)
{
	int i;
	int j;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] != '.' && tab[li + i][col + j] == tetri[i][j])
				tab[li + i][col + j] = '.';
			j++;
		}
		i++;
	}
}
