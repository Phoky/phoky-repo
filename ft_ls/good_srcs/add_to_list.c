/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:56:27 by rcolleau          #+#    #+#             */
/*   Updated: 2017/06/07 14:56:28 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		lstlen(t_dir *b)
{
	int	i;

	i = 0;
	while (b != NULL)
	{
		i++;
		b = b->next;
	}
	return (i);
}

void	add_to_list(t_dir **lst, t_dir *new)
{
	char 	*s;
	t_dir	*tmp;
	t_dir	*t;

	tmp = *lst;
	t = *lst;
	if (tmp == NULL)
	{
		new->root = 1;
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
//		while (new->name->next)
	}
}

void	add_top_list(t_dir **lst, t_dir *new)
{
	new->next = *lst;
	*lst = new;
}

void	add_end_list(t_dir **lst, t_dir *new)
{
	t_dir	*tmp;

	tmp = *lst;
	if (tmp == NULL)
	{
		tmp = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}
