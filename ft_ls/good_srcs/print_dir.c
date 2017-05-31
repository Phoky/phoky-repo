/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:02:26 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/30 10:02:28 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lstlen(t_dir *b)
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

int		hide_file_nbr(char **tbl)
{
	int		i;

	i = 0;
	while (tbl[i][0] == '.')
	{
		i++;
		if (tbl[i] == NULL)
			break ;
	}
	return (i);
}

void	print_dir(t_dir *b, t_arg *opt)
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
	if (opt->lower_a == 1)
		ft_puttbl(tbl);
	if (opt->lower_a == 0)
		ft_puttbl(tbl + hide_file_nbr(tbl));
}
