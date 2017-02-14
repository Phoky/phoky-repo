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

t_list	*lstfind_link(const t_list *lst, int mys)
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

	i = 0;
	tmp = ft_memalloc(BUFF_SIZE);
	if (*content)
		ft_strcpy(tmp, *content);
		ft_strclr(*content);
	while ((ret = read(fd, *buf, BUFF_SIZE)) > 0)
	{
		(*buf)[ret] = '\0';
		if ((i = ft_intchr(*buf, '\n')) < ret)
		{
			tmp = ft_strnjoin(tmp, *buf, i);
			break ;
		}
		else
			tmp = ft_strjoin(tmp, *buf);
	}
	if (ret <= 0)
		return (ret == 0 ? 0 : -1);
	*content = ft_strjoin(*content, (*buf + (i + 1)));
	free(*buf);
	*buf = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int		fill_line(char **line, char **buf, char **content)
{
	int	i;

	i = 0;
//	ft_putstr("[content = ");
//	ft_putstr(*content);
//	ft_putstr("]\n");
	if (*buf)
	{
		if (!(*line = ft_strdup(*buf)))
			return (-1);
		ft_strdel(buf);
	}
	else
	{
		i = ft_intchr(*content, '\n');
		*content[i] = '\0';
		if (!(*line = ft_strndup(*content, i)))
			return (-1);
	}
	*content = (*content + i);
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
	if (!(new = lstfind_link(stock, fd)))
	{
		if (!(new = ft_lstnew("\0", 1)))
			return (-1);
		new->content_size = fd;
		ft_lstadd(&stock, new);
	}
	buf = ft_memalloc(BUFF_SIZE + 1);
	if ((ret = for_read(fd, (char **)&new->content, &buf, ret)) == -1)
		return (-1);
//	ft_putstr("[content = ");
//	ft_putstr((char *)new->content);
//	ft_putstr("]\n");
	if (fill_line(&*line, &buf, (char **)&new->content) != 1)
		return (-1);
//	ft_putstr("[content_end = ");
//	ft_putstr(new->content);	
//	ft_putstr("]\n");
	if ((ret == 0) && (new->content))
		return (0);
	return (1);
}
