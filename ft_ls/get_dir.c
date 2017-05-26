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

int		lstlen(t_bla *b)
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

void	print_dir(t_bla *b, t_arg *opt)
{
	t_bla 	*tmp;
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
	{

		while (**tbl == '.')
			tbl++;
		ft_puttbl(tbl);
	}
}

void	lst_add(t_bla **lst, t_bla *new)
{
	new->next = *lst;
	*lst = new;
}

t_bla	*fill_b(struct dirent *rent)
{
	t_bla	*t;

	t = malloc(sizeof(t_bla));
	t->ino = rent->d_ino;
	t->reclen = rent->d_reclen;
	t->type = rent->d_type;
	t->namlen = rent->d_namlen;
	t->name = rent->d_name;
	return (t);
}

t_bla	*op_dir(char *arg)
{
	struct dirent	*ent;
	DIR				*dir;
	t_bla			*b;
	t_bla			*t;

	dir = opendir(arg);
	ent = malloc(sizeof(struct dirent));
	ent = NULL;
	b = NULL;
	while ((ent = readdir(dir)) != NULL)
	{
		t = malloc(sizeof(t_bla));
		t = fill_b(ent);
		lst_add(&b, t);
	}
	b = t;
	return (b);
}

void	get_dir(char **argv, t_arg *opt)
{
	t_bla	*dir;
	int		i;
	int		j;

	j = 0;
	i = ft_tbllen(argv);
//	ft_putstr("i = ");
//	ft_putnbrendl(i);
//	ft_puttbl(argv);
	if (i == 0)
	{
		dir = op_dir(".");
		print_dir(dir, opt);
	}
	else
	{
		while (j < i)
		{
			dir = op_dir(argv[j]);
			ft_putstr(argv[j]);
			ft_putendl(":");
			print_dir(dir, opt);
			j++;
			ft_putchar('\n');
		}
	}
}
