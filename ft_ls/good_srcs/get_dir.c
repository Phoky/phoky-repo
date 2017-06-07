/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:22:32 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/26 15:18:21 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*fill_b(struct dirent *rent)
{
	t_dir	*t;

	t = malloc(sizeof(t_dir));
	t->ino = rent->d_ino;
	t->reclen = rent->d_reclen;
	t->type = rent->d_type;
	t->namlen = rent->d_namlen;
	t->name = rent->d_name;
	return (t);
}

t_dir	*op_dir(char *arg)
{
	struct dirent	*ent;
	DIR				*dir;
	t_dir			*b;
	t_dir			*t;

	dir = opendir(arg);
	ent = malloc(sizeof(struct dirent));
	ent = NULL;
	b = NULL;
	while ((ent = readdir(dir)) != NULL)
	{
		t = malloc(sizeof(t_dir));
		t = fill_b(ent);
		add_top_list(&b, t);
	}
	b = t;
	return (b);
}

void	get_dir(char **argv, t_arg *opt)
{
	t_dir	*dir;
	int		i;
	int		j;

	j = 0;
	i = ft_tbllen(argv);
	if (i == 0)
	{
		dir = op_dir(".");
		rev_sort_list(&dir);
		print_dir(dir, opt);
	}
	else
	{
		while (j < i)
		{
			dir = op_dir(argv[j]);
			rev_sort_list(&dir);
			if (i > 1)
				ft_put_two_arg(argv[j], ":", 1);
			print_dir(dir, opt);
			j++;
			if (j < i)
				ft_putchar('\n');
		}
	}
}
