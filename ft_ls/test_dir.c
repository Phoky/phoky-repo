#include "libft/libft.h"
#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>

void	print_dir(t_bla *b)
{
	t_bla *tmp;

	tmp = b;
	while (tmp != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void	swap_maillon(t_bla *a, t_bla *b)
{
	t_bla *c;

	ft_putendl(a->name);
	ft_putendl(b->name);
	c = malloc(sizeof(t_bla));
	c = a;
	a = b;
	b = c;
	free (c);
}

void	sort_files(t_bla **b)
{
	t_bla	*tmp;
	char	*swap;
	int		i;

	tmp = *b;
	print_dir(tmp);
//	ft_putnbrendl(42);
	while (tmp->next != NULL)
	{
		i = ft_strcmp(tmp->next->name, tmp->name);
		if (i < 0)
		{
			ft_putnbrendl(i);
			swap_maillon(tmp, tmp->next);
//			sort_files(&tmp);
		}
		tmp = tmp->next;	
	}
//	print_dir(tmp);
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
	t->off = rent->d_off;
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
	else
		dir = opendir(argv[1]);
	rent = malloc(sizeof(struct dirent));
//	b = malloc(sizeof(t_bla));
	rent = NULL;
	b = NULL;

	while ((rent = readdir(dir)) != NULL)
	{
//		ft_putendl(rent->d_name);
		t = malloc(sizeof(t_bla));
		t = fill_b(rent);
//		t = t->next;
//		rent = malloc(sizeof(struct dirent));
		lst_add(&b, t);
	}
	b = t;
//	ft_putendl(b->name);
	sort_files(&b);
	print_dir(b);
	return (0);
}