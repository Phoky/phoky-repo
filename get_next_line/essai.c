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
	ssize_t		i;
	ssize_t		ret;

/* cas d'erreurs */
	if (*line)
		ft_strdel(line);
	if (fd < 0)
		return (-1);
/* Allocation de memoire */
	if (!stock || !stock[fd])
		stock = ft_tbl_memalloc(stock, fd);
//	*line = ft_memalloc(ft_strlen(stock[fd]) + BUFF_SIZE);
/* resolution */
	while (stock[fd])
	{

	}
/* read du file descriptor + resolution */
	while ((ret = read(fd, stock[fd], BUFF_SIZE)))
	{
		while (*stock[fd] == '\n')
			stock[fd]++;
		i = ft_intchr(stock[fd], '\n');
	/* Read ne lit pas de '\n' */
		if ((i == ft_strlen(stock[fd])) && stock[fd][i] != '\n')
		{	
			if (!line)
				*line = ft_strdup(stock[fd]);
			else
				*line = ft_strjoin_free(*line, stock[fd]);
		}
	/* Read lit un seul '\n' */	
	}
/* Valeur de retour */
	if (ret <= 0)
		return (ret = 0 ? 0 : -1);
	return (1);

}
