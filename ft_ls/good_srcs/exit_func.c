/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:39:42 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/30 10:45:32 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_func(int i, char *str)
{
	if (i == 1)
	{
		ft_put_two_arg("ls: illegal option -- ", str, 1);
		error_func("usage: ls [-AFGRUaflrtu1] [file ...]");
		exit(0);
	}
}
