/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:34:29 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/05 14:34:31 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Put the right option to 1 if the option is allowed and called
**	or give the last value of the variable
**	possibility to change to 0 if conflicting options
*/

void	fill_arg(char c, t_arg **arg)
{
	t_arg	*tmp;

	tmp = *arg;
	tmp->l = (c == 'l' ? 1 : tmp->l);
	tmp->upper_r = (c == 'R' ? 1 : tmp->upper_r);
	tmp->lower_r = (c == 'r' ? 1 : tmp->lower_r);
	tmp->upper_a = (c == 'A' ? 1 : tmp->upper_a);
	tmp->lower_a = (c == 'a' ? 1 : tmp->lower_a);
	tmp->lower_a = (c == 'f' ? 1 : tmp->lower_a);
	tmp->t = (c == 't' ? 1 : tmp->t);
	tmp->upper_g = (c == 'G' ? 1 : tmp->upper_g);
	tmp->upper_u = (c == 'U' ? 1 : tmp->upper_u);
	tmp->upper_u = (c == 'f' ? 1 : tmp->upper_u);
	tmp->lower_u = (c == 'u' ? 1 : tmp->lower_u);
	tmp->upper_f = (c == 'F' ? 1 : tmp->upper_f);
	tmp->l = (c == '1' ? 0 : tmp->l);
}

/*
**	Called in main.
**	Check for options while calling program.
**	Give the true option to a t_arg variable if it exist and it's true
**	If an option is not allowed :
**	return the board at the position of the wrong option.
*/

char	*get_arg(char **tbl, t_arg *arg)
{
	char	*list_arg;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (tbl[i] && tbl[i][0] == '-')
	{
		if (!tbl[i][1])
			break ;
		i++;
	}
	list_arg = ft_memalloc(1);
	while (++j < i)
		list_arg = ft_strjoin_free(list_arg, tbl[j] + 1);
	j = -1;
	while (list_arg[++j])
	{
		if (check_char_pres(list_arg[j], "AFGRUaflrtu1") == 0)
			return (list_arg + j);
		fill_arg(list_arg[j], &arg);
	}
	return (NULL);
}
