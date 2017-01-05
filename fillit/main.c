/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:40:29 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/04 15:40:31 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	char	**tbl;
	int		i;
	int		n;

	str = NULL;
	tbl = NULL;
	i = 0;
	n = 3;
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr("Missing File\n");
		else
			ft_putstr("Too Many Files\n");
		return (0);
	}
	if (ft_strequ(str = ft_open_file(argv[1]), "ERROR") == 1)
	{
		ft_putstr("Error");
		return (0);
	}
	tbl = first_split(str);
	if ((ft_strequ(*tbl, "ERROR")) == 1)
	{
		ft_putstr("Error");
		return (0);
	}
//	else
//	{
//		while (*tbl)
//		{
//			ft_putstr(*tbl);
//			tbl++;
//		}
//	}
	return (0);
}
