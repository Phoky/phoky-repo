/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:56:42 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/05 14:56:45 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_dash(char **tbl)
{
	int	i;

	i = 1;
	while (tbl[i][0] == '-')
	{
		i++;
		if (!tbl[i])
			break ;
	}
	return (i);
}

char			**removing_wrong_line(char **tbl, int i)
{
	int		j;
	int		x;
	char	**t;

	j = -1;
	x = ft_tbllen(tbl);
	t = (char **)malloc(sizeof(char *) * x - 1);
	t[x - 1] = NULL;
	while (++j < i)
		t[j] = ft_strdup(tbl[j]);
	while (++i < x)
		t[j++] = ft_strdup(tbl[i]);
	return (t);
}

void			print_res(struct stat *res)
{
	ft_putnbrendl(res->st_dev);
	ft_putnbrendl(res->st_mode);
	ft_putnbrendl(res->st_nlink);
	ft_putnbrendl(res->st_ino);
	ft_putnbrendl(res->st_uid);
	ft_putnbrendl(res->st_gid);
	ft_putnbrendl(res->st_rdev);
	ft_putnbrendl(res->st_size);
	ft_putnbrendl(res->st_blocks);
	ft_putnbrendl(res->st_blksize);
	ft_putnbrendl(res->st_flags);
	ft_putnbrendl(res->st_gen);
	ft_putnbrendl(res->st_lspare);
	ft_putnbrendl(res->st_qspare[0]);
	ft_putnbrendl(res->st_qspare[1]);
	ft_putendl("\n");
}

static char		**check_regular_file(char **arg)
{
	int				i;
	struct stat		inf;

	i = 0;
	if (ft_tbllen(arg) <= 1)
		return (arg);
	while (arg[i])
	{
		ft_putendl(arg[i]);
		if (stat(arg[i], &inf) == -1)
		{
			ft_put_two_arg("ls: ", arg[i], 0);
			ft_putendl(": No such file or directory");
			arg = removing_wrong_line(arg, i);
			i = 0;
		}
		else
			i++;
//		print_res(&inf);
	}
	if (*arg)
	{
		ft_sort_tbl(&arg);
		return (arg);
	}
	else
		exit(0);
}

int				main(int argc, char **argv)
{
	t_arg			a;
	char			*ill_arg;
	int				i;

	i = 1;
	a = (t_arg){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (argc > 1)
	{
		if ((ill_arg = get_arg(argv + 1, &a)) != NULL)
			exit_func(1, ft_strsub(ill_arg, 0, 1));
	}
	if (argc > 1)
		i = check_dash(argv);
	argv = check_regular_file(argv + i);
	get_dir(argv, &a);
	return (0);
}
