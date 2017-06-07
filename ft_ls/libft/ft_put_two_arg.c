/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_two_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:07:29 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/30 10:07:37 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_two_arg(char const *s1, char const *s2, int ret)
{
	if (s1 != NULL)
		write(1, s1, ft_strlen(s1));
	else
		write(1, "(null)", 6);
	if (s2 != NULL)
		write(1, s2, ft_strlen(s2));
	else
		write(1, "(null)", 6);	
	if (ret == 1)
		write(1, "\n", 1);
}
