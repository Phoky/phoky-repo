/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:00:57 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/13 10:59:06 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (big == NULL && DO_SEGFAULT == 1)
		*(volatile int *)0 = 0;
	else if (big == NULL)
		return (NULL);
	while (big + i && ft_strlen(big) - i >= ft_strlen(little))
	{
		if (ft_strnequ(big + i, little, ft_strlen(little)) == 1)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
