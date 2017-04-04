/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:00:51 by rcolleau          #+#    #+#             */
/*   Updated: 2016/11/14 15:09:44 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
	{	
		write(fd, "(null)", 6);
		write(fd, "\n", 1);
	}
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
