/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:49:22 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 10:49:24 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_val	*new_val(char *color)
{
	t_val	*new;

	if ((new = (t_val *)malloc(sizeof(t_val))) == NULL)
		return (NULL);
	if (color == NULL)
		new->color = NULL;
	else
	{
		new->color = ft_strdup(color);
		free(color);
	}
	new->next = NULL;
	return (new);
}
