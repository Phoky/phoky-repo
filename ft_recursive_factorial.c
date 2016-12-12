/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:32:12 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/03 12:18:57 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int r;

	if (nb > 13 || nb < 0)
	{
		r = 0;
		return (r);
	}
	else if (nb == 1 || nb == 0)
	{
		r = 1;
		return (r);
	}
	else
		r = nb * ft_recursive_factorial((nb - 1));
	return (r);
}
