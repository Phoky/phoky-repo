#include "ft_ls.h"

t_dir	*fill_link(t_dir *link)
{
	t_dir	*ret;

	ret = (t_dir *)malloc(sizeof(t_dir));
	ret->ino = link->ino;
	ret->off = link->off;
	ret->reclen = link->reclen;
	ret->type = link->type;
	ret->namlen = link->namlen;
	ret->name = link->name;
	ret->next = link->next;
	return (ret);
}

void	swap_link(t_dir **la, t_dir **lb)
{
	t_dir *t;

	t = *la;
	*la = fill_link(*lb);
	*lb = fill_link(t);
}

void	sort_list(t_dir **list)
{
	t_dir	*tmp;
	t_dir	*t;

	tmp = *list;
	t = tmp->next;
	while (t->next)
	{
		if (ft_strcmp(t->name, tmp->name) < 0)
		{
			swap_link(&t, &tmp);
			tmp = *list;
			t = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			t = t->next;
		}
	}
}