/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:00:57 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/12 15:10:47 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (big == NULL)
		return (ft_strtrim(big+12));
	while (big + i && ft_strlen(big) - i >= ft_strlen(little))
	{
		if (ft_strnequ(big + i, little, ft_strlen(little)) == 1)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
