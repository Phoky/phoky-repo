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

int		fill_buf_w_cont(char **content, char **buf)
{
	int	i;

	i = ft_intchr(*content, '\n');
	if (i < (int)ft_strlen(*content))
	{
		*content[i] = '\0';
		if (i == 0)
			i++;
		ft_strncpy(*buf, *content, i);
		*content = (*content + i);
		return (1);
	}
	else
	{
		ft_strcpy(*buf, *content);
		ft_strclr(*content);
		return (2);
	}
	return (0);
}

int		for_read(const int fd, char **content, char **buf, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((ft_strlen(*content)) && (i = fill_buf_w_cont(&*content, &*buf)))
		if (i <= 1)
			return (i == 1 ? 1 : 0);
	tmp = ft_memalloc(BUFF_SIZE + 1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if ((i = ft_intchr(tmp, '\n')) < ret)
		{
			tmp[i] = '\0';
			*buf = ft_strnjoin(*buf, tmp, i);
			break ;
		}
		else
			*buf = ft_strjoin_free(*buf, tmp);
	}
	*content = ft_strjoin(*content, (tmp + (i + 1)));
	free(tmp);
	if (ret <= 0 && !(ft_strlen(*buf)))
		return (ret == 0 ? 0 : -1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*stock;
	t_list			*new;
	char			*buf;
	int				ret;

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
	ret = for_read(fd, (char **)&new->content, &buf, 0);
	if ((ret <= 0))
		return (ret == 0 ? 0 : -1);
	*line = ft_strdup(buf);
	free(buf);
	if (**line == '\n')
		ft_strclr(*line);
	return (1);
}
