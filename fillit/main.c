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

//void		printtbl(char ***tbl)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (tbl[i])
//	{
//		while (tbl[i][j])
//		{
//			ft_putstr(tbl[i][j]);
//			j++;
//		}
//		i++;
//		j = 0;
//	}
//}

int		main(int argc, char **argv)
{
	char	**tbl;
	char	*str;

	tbl = NULL;
	str = NULL;
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr("Missing File\n");
		else
			ft_putstr("Too Many Files\n");
		return (0);
	}
	if ((ft_strequ((str = open_file(argv[1])), "ERROR") == 1))
	{
		ft_putendl("Error");
		return (0);
	}
	tbl = first_split(str);
	final_split(tbl);
//	if ((ft_strequ(*tbl, "ERROR")) == 1)
//	{
//		ft_putstr("Error");
//		return (0);
//	}
//	else
//		printtbl(tbl);
	return (0);
}
