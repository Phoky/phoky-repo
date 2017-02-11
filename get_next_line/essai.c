#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char	**ft_tbl_memalloc(char **tbl, int i)
{
	if (!tbl)
		tbl = (char **)malloc(sizeof(char *) * OPEN_MAX);
	if (!tbl[i])
		tbl[i] = ft_memalloc(BUFF_SIZE + 1);
	return (tbl);
}

int		get_next_line(const int fd, char **line)
{
/* Declaration des variables */
	static char	**stock;
	size_t		i;
	ssize_t		ret;

/* cas d'erreurs */
	if (*line)
		ft_strdel(line);
	if (fd < 0)
		return (-1);
/* Allocation de memoire */
	if (!stock || !stock[fd])
		stock = ft_tbl_memalloc(stock, fd);
	*line = ft_memalloc(ft_strlen(stock[fd]) + BUFF_SIZE);
/* resolution */
	/* stock contient plusieurs '\n' */
	if (ft_strlen(stock[fd]))
	{
		i = ft_intchr(stock[fd], '\n');
		if (i < ft_strlen(stock[fd]))
		{
			*line = ft_strnjoin_free(*line, stock[fd], i);
//			ft_putstr("[stock_aft_read = ");
//			ft_putstr(stock[fd]);
//			ft_putendl("]");
			while (*stock[fd] != '\n')
				stock[fd]++;
			return (1);
		}
		else
		{
			*line = ft_strjoin_free(*line, stock[fd]);
			ft_strclr(stock[fd]);
		}
	}
/* read du file descriptor + resolution */
	while ((ret = read(fd, stock[fd], BUFF_SIZE)))
	{
//		ft_putstr("[stock_aft_read = ");
//		ft_putstr(stock[fd]);
//		ft_putendl("]");
//		ft_putstr("[line_aft_read = ");
//		ft_putstr(*line);
//		ft_putendl("]");
		stock[fd][ret] = '\0';
		i = ft_intchr(stock[fd], '\n');
//		ft_putstr("[*stock[fd] = ");
//		ft_putchar(*stock[fd]);
//		ft_putendl("]");
	/* Read ne lit pas de '\n' || stock[fd][i] == '\n' */
		
		if (stock[fd][i] == '\n')
		{
			*line = ft_strnjoin_free(*line, stock[fd], i);
			if 	 (stock[fd][i + 1] == '\0')
				ft_strclr(stock[fd]);
			if (*line == '\0')
				ft_strclr(*line);
			break ;
		}
		else if ((i == ft_strlen(stock[fd])) && stock[fd][i] != '\n')
		{
			*line = ft_strjoin_free(*line, stock[fd]);
		}		
	/* Read lit un seul '\n' */	
		else if (i < ft_strlen(stock[fd]))
		{
			if (!line)
				ft_strncpy(*line, stock[fd], i);
			else
			{
				*line = ft_strnjoin_free(*line, stock[fd], i);
				while (*stock[fd] != '\n')
					stock[fd]++;
			}
			break ;
		}
	/* read lit plusieurs '\n' */
		/* idem lit 1 seul + resolution [if (ft_strlen(stock[fd])] */
	}
/* Deplacement du pointeur de stock[fd] */
	while (i)
	{
		stock[fd]++;
		i--;
	}
	while (*stock[fd] == '\n')
		stock[fd]++;
/* Valeur de retour */
//	ft_putstr("[stock_end = ");
//	ft_putstr(stock[fd]);
//	ft_putendl("]");
	ft_putstr("[line_end = ");
	ft_putstr(*line);
	ft_putendl("]");
	if (ret <= 0)
		return (ret = 0 ? 0 : -1);
	return (1);

}
