/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:41:57 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/27 12:42:00 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*open_file(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*sf;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("read error\n");
		return ("ERROR");
	}
	if ((sf = ft_memalloc(BUF_SIZE + 1)) == NULL)
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		sf = ft_strjoin_free(sf, buf);
	}
	return (sf);
}

int				ft_filecmp(char *arg1, char *arg2)
{
	char *s;
	char *s1;

	s = open_file(arg1);
	s1 = open_file(arg2);
	return (ft_strcmp(s, s1));
}
