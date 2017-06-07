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

void	dir_print(t_dir *b)
{
	t_dir	*tmp;
	int		i;
	char	**tbl;

	tmp = b;
	i = lstlen(b);
	tbl = (char **)malloc(sizeof(char *) * i + 1);
	tbl[i] = NULL;
	i--;
	while (tmp != NULL)
	{
		tbl[i] = ft_strdup(tmp->name);
		i--;
		tmp = tmp->next;
	}
}

void	add_top_list(t_dir **lst, t_dir *new)
{
	new->next = *lst;
	*lst = new;
	dir_print(*lst);
}

void	add_end_list(t_dir **lst, t_dir *new)
{
	t_dir	*tmp;

	tmp = *lst;
	dir_print(tmp);
	if (tmp == NULL)
		tmp = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next = NULL;
	}
}
