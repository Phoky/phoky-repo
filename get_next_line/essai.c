#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char	**ft_tbl_memalloc(char **tbl, int i)
{
	if (!tbl)
		tbl = (char **)malloc(sizeof(char *) * 12);
	if (!tbl[i])
		tbl[i] = ft_memalloc(BUFF_SIZE + 1);
	return (tbl);
}

int		get_next_line(const int fd, char **line)
{
/* Declaration des variables */
	static char	**stock;
	ssize_t		i;
	ssize_t		ret;

/* cas d'erreurs */
	if (*line)
		ft_strclr(*line);
	if (fd < 0)
		return (-1);
/* Allocation de memoire */
	if (!stock || !stock[fd])
		stock = ft_tbl_memalloc(stock, fd);
	*line = ft_memalloc(ft_strlen(stock[fd]) + BUFF_SIZE);
/* resolution */
	if (stock[fd])
	{
		i = ft_intchr(stock[fd], '\n');
		if (i < ft_strlen(stock[fd]))
		{
			if (!line)
				ft_strncpy(*line, stock[fd], (i - 1));
			else
				*line = ft_strnjoin_free(*line, stock[fd], (i - 1));
			while (i)
			{
				stock[fd]++;
				i--;
				while (*stock[fd] == '\n')
					stock[fd]++;
			}
			return (1);
		}
		else
			ft_strjoin_free(*line, stock[fd]);
	}
/* read du file descriptor + resolution */
	while ((ret = read(fd, stock[fd], BUFF_SIZE)))
	{
		stock[fd][ret] = '\0';
		i = ft_intchr(stock[fd], '\n');
	/* Read ne lit pas de '\n' */
		if (*stock[fd] == '\n')
			break ;
		if ((i == (ssize_t)ft_strlen(stock[fd])) && stock[fd][i] != '\n')
		{	
			if (!ft_strlen(*line))
				ft_strcpy(*line, stock[fd]);
			else
				*line = ft_strjoin_free(*line, stock[fd]);
			ft_strclr(stock[fd]);
		}
	/* Read lit un '\n' a la fin de stock[fd] */
		else if (stock[fd][i] == '\n')
		{
			if (!ft_strlen(*line))
				ft_strncpy(*line, stock[fd], (i - 1));
			else
				*line = ft_strnjoin_free(*line, stock[fd], (i - 1));
			ft_strclr(stock[fd]);
			return (1);
		}
	/* Read lit un ou plusieurs '\n' */
		else
		{
			if (!ft_strlen(*line))
				ft_strncpy(*line, stock[fd], i);
			else
				*line = ft_strnjoin_free(*line, stock[fd], i);
			break ;
		}
	}
/* Valeur de retour */
	if (ret <= 0)
		return (ret = 0 ? 0 : -1);
	return (1);

}
