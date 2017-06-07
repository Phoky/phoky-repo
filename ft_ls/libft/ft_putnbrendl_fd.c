/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:18:23 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/30 21:53:53 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrendl_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n)
	{
		i = n % 10;
		n = n / 10;
		if (n)
			ft_putnbr_fd(n, fd);
		i = i + 48;
		write(fd, &i, 1);
	}
	write(fd, "\n", 1);
}
