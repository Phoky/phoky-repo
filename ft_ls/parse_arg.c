#include "libft/libft.h"
#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>

int		fill_arg(char c, t_arg **arg)
{
	t_arg	*tmp;
	int		i;

	i = 1;
	tmp = *arg;
	if (c == 'l')
		tmp->l = 1;
	else if (c == 'R')
		tmp->upper_r = 1;
	else if (c == 'r')
		tmp->lower_r = 1;
	else if (c == 'A')
		tmp->upper_a = 1;
	else if (c == 'a')
		tmp->lower_a = 1;
	else if (c == 't')
		tmp->t = 1;
	else if (c == 'G')
		tmp->upper_g = 1;
	else if (c == 'u')
		tmp->u = 1;
	else if (c == 'F')
		tmp->upper_f = 1;
	else
		i = 0;
	return (i);
}

char	*get_arg(char **tbl, t_arg **arg)
{
	char 	*ret;
	t_arg	*tmp;
	char	*list_arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = NULL;
	while (tbl[i] && tbl[i][0] == '-')
		i++;
	ft_putnbrendl(i);
	list_arg = ft_memalloc(1);
	while (j < i)
	{
		list_arg = ft_strjoin_free(list_arg, tbl[j] + 1);
		j++;
	}
	ft_putendl(list_arg);
	ret = "2";
	if (ret != NULL)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putendl(ret);
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	struct dirent	*rent;
	DIR				*dir;
	t_bla			*b;
	t_bla			*t;
	t_arg			*a;
	char			*ill_arg;

	if ((ill_arg = get_arg(argv + 1, &a)) != NULL)
	{
		return (error_func("usage: ls [-AFGRalrtu1] [file ...]"));
	}
	return (0);
}
