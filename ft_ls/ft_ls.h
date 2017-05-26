/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:57:32 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/05 14:59:50 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>


typedef struct		s_bla
{
	ino_t			ino;
	off_t			off;
	unsigned short	reclen;
	unsigned char	type;
	unsigned char	namlen;
	char			*name;
	struct s_bla	*next;
}					t_bla;

typedef struct		s_arg
{
	int				l;
	int				upper_r;
	int				lower_r;
	int				upper_a;
	int				lower_a;
	int				t;
	int				upper_g;
	int				upper_u;
	int				lower_u;
	int				upper_f;
}					t_arg;

int					main(int argc, char **argv);

/*
** 		parse_arg.c
*/
char				*get_arg(char **tbl, t_arg *arg);
void				fill_arg(char c, t_arg **arg);


/*
**		get_dir.c
*/
void				get_dir(char **argv, t_arg *opt);

#endif
