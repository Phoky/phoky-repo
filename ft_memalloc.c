/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:48:35 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/02 15:12:39 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (size == 0)
		mem = malloc(1);
	else if (size != 0)
		mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	return (mem);
}
