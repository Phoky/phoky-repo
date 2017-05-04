#include "libft/libft.h"
#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>

void	print_dir(t_bla *b, char *arg)
{
	t_bla 	*tmp;
	int		i;
	char	**tbl;

	tmp = b;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	tbl = (char **)malloc(sizeof(char *) * i + 1);
	tbl[i] = NULL;
	i--;
	tmp = b;
	while (tmp != NULL)
	{
		tbl[i] = ft_strdup(tmp->name);
		i--;
		tmp = tmp->next;
	}
	if (arg && ft_strcmp(arg, "-a") == 0)
		ft_puttbl(tbl);
	else if (arg == NULL)
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
	t->name = rent->d_name;
	return (t);
}

int		main(int argc, char **argv)
{
	struct dirent	*rent;
	DIR				*dir;
	t_bla			*b;
	t_bla			*t;

	if (argc == 1)
		dir = opendir(".");
	else if (argc == 2)
	{
		if (*argv[1] == '-')
			dir = opendir(".");
		else
			dir = opendir(argv[1]);
	}
	else
		dir = opendir(argv[2]);
	rent = malloc(sizeof(struct dirent));
	rent = NULL;
	b = NULL;

	while ((rent = readdir(dir)) != NULL)
	{
		t = malloc(sizeof(t_bla));
		t = fill_b(rent);
		lst_add(&b, t);
	}
	b = t;
	if (argc == 2 && ft_strcmp(argv[1], "-a") == 0)
		print_dir(b, argv[1]);
	else if (argc == 3 && ft_strcmp(argv[1], "-a") == 0)
		print_dir(b, argv[1]);
	else
		print_dir(b, NULL);
	closedir(dir);
	return (0);
}