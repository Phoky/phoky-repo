/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tritbllen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:55:34 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/14 10:55:40 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tritbllen(char ***tbl)
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
