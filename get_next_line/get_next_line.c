/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:47:13 by rcolleau          #+#    #+#             */
/*   Updated: 2017/02/04 16:47:28 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	**ft_alloc(char **tbl, int i)
{
	if (!tbl)
	{
		tbl = (char **)malloc(sizeof(char *) * OPEN_MAX);
		tbl[i] = ft_memalloc(BUFF_SIZE + 1);
	}
	if (!tbl[i])
		tbl[i] = ft_memalloc(BUFF_SIZE + 1);
	return (tbl);
}

int		get_next_line(const int fd, char **line)
{
	static char		**stock;
	ssize_t			i;
	ssize_t			ret;

	i = 0;
	if (line)
		ft_strclr(*line);
	if (fd < 0 )
		return (-1);
	if (!stock || !stock[fd])
		stock = ft_alloc(stock, fd);
	*line = ft_memalloc(ft_strlen(stock[fd]) + BUFF_SIZE);
	if (ft_strlen(stock[fd]))
	{
		if ((i = ft_intchr(stock[fd], '\n')) < (ssize_t)(ft_strlen(stock[fd])))
		{
			ft_strncpy(*line, stock[fd], (i));
			while (i)
			{
				stock[fd]++;
				i--;
				while (*stock[fd] == '\n')
					stock[fd]++;
			}
			return (1);
		}
		else if ((read(fd, stock[fd], BUFF_SIZE) == 0) &&
			(ft_strlen(stock[fd]) < BUFF_SIZE) && (stock[fd][ft_strlen(stock[fd])] != '\n'))
		{
			ft_strcpy(*line, stock[fd]);
			ft_strclr(stock[fd]);
			return (1);
		}
		else
		{
			ft_strcpy(*line, stock[fd]);
			ft_strclr(stock[fd]);
		}
	}
	while ((ret = read(fd, stock[fd], BUFF_SIZE)))
	{
		stock[fd][ret] = '\0';
		if (stock[fd][ret - 1] == '\n')
		{
			stock[fd][ret - 1] = '\0';
			if ((i = ft_intchr(stock[fd], '\n')) < (ret - 1))
				ft_strncat(*line, stock[fd], i);
			else
				ft_strcat(*line, stock[fd]);
			break ;
		}
		else if (*stock[fd] == '\n')
		{
			if (line)
			{
				i = 0;
				while (*stock[fd] == '\n')
					stock[fd]++;
				break ;
			}
			else
			{
				while (*stock[fd] == '\n')
					stock[fd]++;
				if ((i = ft_intchr(stock[fd], '\n')) < (ssize_t)(ft_strlen(stock[fd])))
					ft_strncat(*line, stock[fd], i);
				else
					ft_strcat(*line, stock[fd]);
			}
		}
		else
		{
			if ((i = ft_intchr(stock[fd], '\n')) < (BUFF_SIZE - 1))
			{
				ft_strncat(*line, stock[fd], i);
				break ;
			}
			else
				ft_strcat(*line, stock[fd]);
		}
	}
	while (i)
	{
		stock[fd]++;
		i--;
	}
	while (*stock[fd] == '\n' && (ret != 0))
		stock[fd]++;
	if (ret <= 0)
			return (ret = 0 ? 0 : -1);
	return (1);
}
