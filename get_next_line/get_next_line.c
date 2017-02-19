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

void	ft_delete_link(void *content, size_t content_size)
{
	if (content && content_size)
	{
		free(content);
		content = NULL;
	}
}

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
	int		i;
	char	tmp[ft_strlen(*content)];

	ft_strcpy(tmp, *content);
	free(*content);
	i = ft_intchr(tmp, '\n');
	if (i < (int)ft_strlen(tmp))
	{
		i++;
		ft_strncpy(*buf, tmp, (i - 1));
		*content = ft_strdup((tmp + i));
		return (1);
	}
	else
	{
		ft_strcpy(*buf, tmp);
		*content = ft_memalloc(1);
		return (2);
	}
}

int		for_read(const int fd, char **content, char **buf, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((ft_strlen(*content) && ((i = fill_buf_w_cont(&*content, &*buf)) == 1)))
		return (1);
	tmp = ft_memalloc(BUFF_SIZE + 1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if ((i = ft_intchr(tmp, '\n')) < ret)
		{
			tmp[i] = '\0';
			*buf = ft_strnjoin_free(*buf, tmp, i);
			break ;
		}
		else
			*buf = ft_strjoin_free(*buf, tmp);
	}
	if (ret != 0)
		*content = ft_strjoin_free(*content, (tmp + (i + 1)));
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

	if (fd < 0 || !(line) || BUFF_SIZE <= 0)
		return (-1);
	if (!(new = lstfind_link(stock, fd)))
	{
		if (!(new = ft_lstnew("\0", 1)))
			return (-1);
		new->content_size = fd;
		ft_lstadd(&stock, new);
	}
	buf = ft_memalloc(BUFF_SIZE + 1);
	ret = for_read(fd, (char **)&new->content, &buf, 0);
	if (ret > 0)
		*line = ft_strdup(buf);
	ft_strdel(&buf);
	if ((ret <= 0))
		return (ret == 0 ? 0 : -1);
	return (1);
}
