/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:49:27 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 10:49:30 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_val(t_val *chain)
{
	t_val	*t;

	t = chain;
	while (t)
	{
		ft_putstr("[Value = ");
		ft_putnbr(t->value);
		ft_putendl("]");
		ft_putstr("[x = ");
		ft_putnbr(t->x);
		ft_putendl("]");
		ft_putstr("[y = ");
		ft_putnbr(t->y);
		ft_putendl("]");
		if (t->color != NULL)
		{
			ft_putstr("[color = ");
			ft_putstr(t->color);
			ft_putendl("]");
		}
		t = t->next;
	}
}
