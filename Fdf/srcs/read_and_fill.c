/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 10:49:35 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 10:49:41 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*read_and_fill(t_list *chain, char *argv)
{
	t_list	*new;
	int		fd;
	int		ret;
	char	*s;

	fd = open(argv, O_RDONLY);
	while ((ret = get_next_line(fd, &s)) > 0)
	{
		if (*s == '\0')
			return (NULL);
		if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new->content = ft_strsplit(s, ' ');
		new->content_size = ft_tbllen(new->content);
		ft_lstadd_end(&chain, new);
		new = new->next;
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (chain);
}
