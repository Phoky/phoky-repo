/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:35:10 by rcolleau          #+#    #+#             */
/*   Updated: 2017/03/29 18:07:46 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_open_file(char *str)
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
		ft_putendl(buf);
		buf[ret] = '\0';
		sf = ft_strjoin_free(sf, buf);
	}
	return (sf);
}
