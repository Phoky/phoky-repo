/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:46:23 by rcolleau          #+#    #+#             */
/*   Updated: 2017/02/13 12:46:26 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		lst_find_link(const t_list *lst, int mys)
{
	t_list	*find_me;

	if (!lst)
		return (NULL);
	find_me = (t_list *)lst;
	while (find_me && (int)find_me->content_size != mys)
		find_me = find_me->next;
	return (find_me);
}

int		for_read(const int fd, char **content, char **buf, int ret)
{
	int		i;
	char	*tmp;

	while (ret = read(fd, *buf, BUFF_SIZE))
	{
		if (ret == -1)
			return (-1)
		*buf[ret] = '\0'
		i = ft_intchr(*buf, '\n');
		*buf[i] = '\0';
		tmp = ft_strjoin_free(*content, *buf);
		*content = tmp;
	}
	return (ret);
}

int		to_fill()
{
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*stock;
	t_list			*new;
	char			*buf;
	int				ret;

	ret = 0;
	if (!fd || fd <= 0)
		return (-1);
	if (line && *line)
		ft_strdel(line);
	if (!(new = find_link(stock, fd)))
	{
		if (!(buff = ft_lstnew("\0", fd)))
			return (-1);
		buff->content_size = fd;
		ft_lstadd(&stock, buff);
	}
	buf = ft_memalloc(BUFF_SIZE + 1);
	if ((ret = for_read(fd, (char **)&new->content, &buf, ret)) < 0)
		return (-1);
	if (ret == 0 && !new->content)
		return (0);
	if (!(to_fill()))
		return (-1);
	return (1);
}