/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:29:05 by cbouvell          #+#    #+#             */
/*   Updated: 2017/01/10 16:38:11 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	swap_tetri(char ***tetri, int n)
{
	char **c;

	c = tetri[n];
	tetri[n] = tetri[n + 1];
	tetri[n + 1] = c;
}