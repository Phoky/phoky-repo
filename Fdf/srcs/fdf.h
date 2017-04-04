/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:50:00 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 10:50:01 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define CLEAR_GREEN 0x00FF00
# define HARD_GREEN 0x007700
# define CLEAR_RED 0xAF0000
# define HARD_RED 0xFF0000

typedef	struct		s_val
{
	int				value;
	int				x;
	int				y;
	char			*color;
	struct s_val	*next;
}					t_val;

int					main(int argc, char **argv);
t_list				*read_and_fill(t_list *chain, char *argv);
t_val				*crea_lstval(t_val *chain, t_list *alst, int i);
t_val				*new_val(char *color);
void				print_val(t_val *chain);
void				window_crea(t_val **chain);

#endif
