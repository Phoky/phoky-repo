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

	str = NULL;
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr("Missing File\n");
		else
			ft_putstr("Too Many Files\n");
		return (0);
	}
	str = ft_open_file(argv[1]);
	ft_putstr(str);
}
