/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:53:08 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/16 16:13:18 by cbouvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

//# define BUF_SIZE 39

int		main(int argc, char **argv);
char	*open_file(char *str);
char	**first_split(char *str);
char	***final_split(char **tbl);
int		chk_tetri(char **tetri);
void	tetri_on(char **tab, char **tetri, int li, int col);
void	ft_puttab(char **tab);
int		cmp_tetri_tab(char **tetri, char **tab, int li, int col);
void	swap_tetri(char ***tetri, int n);
void	tetri_off(char **tab, char **tetri, int li, int col);
char	**mv_tetra(char **tetra);
char	**crea_tab(int size);
char	**mk_all(char ***tetri, int sz_min);
int		bck_trck(char ***tetra, char **tab, int j);

#endif
