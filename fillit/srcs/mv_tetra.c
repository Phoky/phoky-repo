/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_tetra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:43:15 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/13 15:45:51 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		empty_li(char **tetra)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i])
	{
		j = 0;
		while (tetra[i][j])
		{
			if (tetra[i][j] != '.')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static int		empty_col(char **tetra)
{
	int i;
	int j;
	int col;

	i = 0;
	j = 0;
	col = 4;
	while (tetra[i])
	{
		j = 0;
		while (tetra[i][j])
		{
			if (tetra[i][j] != '.' && j < col)
				col = j;
			j++;
		}
		i++;
	}
	return (col);
}

static int		move_tetri(char **tetra, int i, int li, int col)
{
	int	j;

	while (i < 4 - li)
	{
		j = 0;
		while (j < 4 - col)
		{
			if (tetra[li + i][col + j])
				tetra[i][j] = tetra[li + i][col + j];
			j++;
		}
		while (j >= 4 - col && j < 4)
		{
			tetra[i][j] = '.';
			j++;
		}
		tetra[i][4] = '\0';
		i++;
	}
	return (i);
}

char			**mv_tetra(char **tetra)
{
	int i;
	int j;
	int li;
	int col;

	li = empty_li(tetra);
	col = empty_col(tetra);
	j = 0;
	i = move_tetri(tetra, 0, li, col);
	while (i >= 4 - li && i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tetra[i][j] = '.';
			j++;
		}
		tetra[i][j] = '\0';
		i++;
	}
	return (tetra);
}
