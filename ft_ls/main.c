/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:56:42 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/05 14:56:45 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_arg			a;
	char			*ill_arg;
	int				i;

	i = 1;
	a = (t_arg){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (argc > 1)
	{
		if ((ill_arg = get_arg(argv + 1, &a)) != NULL)
		{
			ft_putstr("ls: illegal option -- ");
			ft_putendl(ft_strsub(ill_arg, 0, 1));
			return (error_func("usage: ls [-AFGRUaflrtu1] [file ...]"));
		}
	}
//	ft_putstr("l = ");
//	ft_putnbrendl(a.l);
//	ft_putstr("R = ");
//	ft_putnbrendl(a.upper_r);
//	ft_putstr("r = ");
//	ft_putnbrendl(a.lower_r);
//	ft_putstr("A = ");
//	ft_putnbrendl(a.upper_a);
//	ft_putstr("a = ");
//	ft_putnbrendl(a.lower_a);
//	ft_putstr("t = ");
//	ft_putnbrendl(a.t);
//	ft_putstr("G = ");
//	ft_putnbrendl(a.upper_g);
//	ft_putstr("U = ");
//	ft_putnbrendl(a.upper_u);
//	ft_putstr("u = ");
//	ft_putnbrendl(a.lower_u);
//	ft_putstr("F = ");
//	ft_putnbrendl(a.upper_f);
	if (argc > 1)
	{
		while (argv[i][0] == '-')
		{
			i++;
			if (!argv[i])
				break ;
		}
	}	
//	ft_putstr("i = ");
//	ft_putnbrendl(i);
	get_dir(argv + i, &a);
	return (0);
}
