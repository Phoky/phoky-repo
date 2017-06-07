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

/*
**	Check the number of dash/option of the argv variable
*/

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

/*
**	Called in check_regular_file if a file or directory doesn't exist
**	create a new board without the wrong argument
*/

char			**removing_wrong_line(char **tbl, int *i)
{
	int		j;
	int		x;
	char	**t;

	j = -1;
	x = ft_tbllen(tbl);
	t = (char **)malloc(sizeof(char *) * x - 1);
	t[x - 1] = NULL;
	while (++j < *i)
		t[j] = ft_strdup(tbl[j]);
	while (++*i < x)
		t[j++] = ft_strdup(tbl[*i]);
	*i = 0;
	return (t);
}

/*
**	Completion for check_regular_file for special case
**	if len of arg <= 1
*/

int				length_and_valid(char **arg)
{
	int				i;
	struct stat		inf;

	i = ft_tbllen(arg);
	if (i == 0)
		return (1);
	else if (i == 1)
	{
		if (stat(arg[0], &inf) == -1)
		{
			ft_put_two_arg("ls: ", arg[0], 0);
			ft_putendl(": No such file or directory");
			return (0);
		}
		else
			return (1);
	}
	return (1);
}

/*
**	Check if all arguments truely exist
**	Return a board with existing arguments
**	or exit programm if any arguments are valid
*/

static char		**check_regular_file(char **arg, int i)
{
	struct stat		inf;

	if (ft_tbllen(arg) <= 1)
	{
		if ((length_and_valid(arg)) == 1)
			return (arg);
		else
			return (NULL);
	}
	ft_sort_tbl(&arg);
	while (arg[i])
	{
		if (stat(arg[i], &inf) == -1)
		{
			ft_put_two_arg("ls: ", arg[i], 0);
			ft_putendl(": No such file or directory");
			arg = removing_wrong_line(arg, &i);
		}
		else
			i++;
	}
	if (*arg)
		return (arg);
	return (NULL);
}

/*
**	MAIN :
**	Parsing options,
**	Checking for wrong called files or directory
**	Calling for get_dir.
*/

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
	if ((argv = check_regular_file((argv + i), 0)) == NULL)
		exit(0);
	get_dir(argv, &a);
	return (0);
}
