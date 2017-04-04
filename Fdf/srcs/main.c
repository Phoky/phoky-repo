/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:49:13 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 10:49:16 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_list	*r;
	t_val	*ch;

	if (argc != 2)
		return (error_func("usage: ./fdf <filename>"));
	r = ft_lstnew(NULL, 0);
	if ((read_and_fill(r, argv[1])) == NULL)
		return (error_func("error while reading the file"));
	free(r);
	r = r->next;
	ch = new_val(NULL);
	if ((crea_lstval(ch, r, r->content_size)) == NULL)
		return (error_func("error in the file"));
	free(ch);
	ch = ch->next;
//	print_val(ch);
	window_crea(&ch);
	return (0);
}
