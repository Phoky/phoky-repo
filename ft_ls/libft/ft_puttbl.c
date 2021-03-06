/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:34:19 by rcolleau          #+#    #+#             */
/*   Updated: 2017/03/03 10:34:21 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttbl(char **tbl)
{
	if (*tbl != NULL)
	{
		while (*tbl)
		{
			write(1, *tbl, ft_strlen(*tbl));
			ft_putchar('\n');
			tbl++;
		}
	}
}
