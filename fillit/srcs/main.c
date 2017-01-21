/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:40:29 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/21 17:28:38 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	cherr(char ***tbl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tbl[i])
	{
		if (ft_tbllen(tbl[i]) != 4)
			return (0);
		while (tbl[i][j])
		{
			if ((ft_strlen(tbl[i][j])) != 4)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	ft_error(int argc)
{
	if (argc == 1)
		ft_putendl("Missing File");
	else if (argc == 0)
		ft_putendl("error");
	else
		ft_putendl("Too Many Files");
	return (0);
}

static int	ft_tetri_error(char **tbl)
{
	if ((ft_strequ(*tbl, "ERROR")) == 1)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	char	***tf;
	char	**pzl;
	int		i;

	tf = NULL;
	pzl = NULL;
	i = 0;
	if (argc != 2)
		return (ft_error(argc));
	if ((ft_tetri_error(first_split(open_file(argv[1])))) == 0)
		return (ft_error(0));
	tf = final_split(first_split(open_file(argv[1])));
	if (cherr(tf) == 0)
		return (ft_error(0));
	while (tf[i])
	{
		mv_tetra(tf[i]);
		if (chk_tetri(tf[i]) == 0)
			return (ft_error(0));
		i++;
	}
	pzl = mk_all(tf, i * 4);
	ft_puttab(pzl);
	return (0);
}
