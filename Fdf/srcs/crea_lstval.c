/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_lstval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:48:17 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 10:48:18 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_to_end(t_val **chain, t_val *new)
{
	t_val *tmp;

	tmp = *chain;
	if (tmp == NULL)
	{
		tmp = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}

int		parse_color(const char *s)
{
	size_t	i;
	size_t	j;

	i = ft_intchr(s, ',');
	j = 0;
	if (i < ft_strlen(s))
	{
		i++;
		j = i;
		if ((s[j] != 0) && (s[j + 1] != 'x'))
			return (0);
		j += 2;
		while (j < ft_strlen(s))
		{
			if ((ft_isdigit(s[j]) == 0) && (s[j] < 65 && s[j] > 70))
				return (0);
			else
				j++;
		}
	}
	return (i);
}

t_val	*fill_val(t_val *block, char *arg, int x, int y)
{
	size_t	p;

	p = 0;
	if (((p = parse_color(arg))) < (ft_strlen(arg)) && p != 0)
		block = new_val(ft_strsub(arg, p, 8));
	else
		block = new_val(NULL);
	block->value = ft_atoi(arg);
	block->x = x;
	block->y = y;
	block->next = NULL;
	return (block);
}

int		check_len(t_list **alst)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = *alst;
	i = tmp->content_size;
	while (tmp)
	{
		if (tmp->content_size != i)
			return (0);
		else
			tmp = tmp->next;
	}
	free(tmp);
	return (i);
}

t_val	*crea_lstval(t_val *chain, t_list *alst, int i)
{
	t_list	*tmp;
	t_val	*new;
	char	**tab;
	int		it[2];

	tmp = alst;
	it[0] = 0;
	new = NULL;
	if ((check_len(&alst)) == 0)
		return (NULL);
	while (tmp)
	{
		it[1] = 0;
		tab = tmp->content;
		while (it[1] < i)
		{
			new = fill_val(new, *tab, it[1], it[0]);
			add_to_end(&chain, new);
			tab++;
			it[1]++;
		}
		it[0]++;
		tmp = tmp->next;
	}
	return (new);
}
