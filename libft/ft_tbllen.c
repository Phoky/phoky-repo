/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tbllen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:55:24 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/14 10:55:27 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tbllen(char **tbl)
{
	int	i;

	i = 0;
	while (*tbl)
	{
		i++;
		tbl++;
	}
	return (i);
}