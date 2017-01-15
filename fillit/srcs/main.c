/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:40:29 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/14 16:25:49 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_arg(int argc)
{
	if (argc == 1)
		ft_putendl("Missing File");
	else if (argc == 0)
		ft_putendl("Error");
	else
		ft_putendl("Too Many Files");
	return (0);
}

static int	check_t(char ***tbl)
{
	int	i;

	i = 0;
	while (tbl[i])
	{
		if ((chk_tetri(tbl[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	char	**tbl;
	char	***tf;
	char	**pzl;
	int		i;

	tbl = NULL;
	tf = NULL;
	pzl = NULL;
	i = 0;
	if (argc != 2)
		return (check_arg(argc));
	tbl = first_split(open_file(argv[1]));
	if ((ft_strequ(*tbl, "ERROR")) == 1)
		return (check_arg(0));
	tf = final_split(tbl);
	if ((check_t(tf)) == 0)
		return (check_arg(0));
	while (tf[i])
		mv_tetra(tf[i++]);
	pzl = mk_all(tf);
	ft_puttab(pzl);
	return (0);
}
