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
			exit_func(1, ft_strsub(ill_arg, 0, 1));
	}
	if (argc > 1)
	{
		while (argv[i][0] == '-')
		{
			i++;
			if (!argv[i])
				break ;
		}
	}
	get_dir(argv + i, &a);
	return (0);
}
