#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char	**ft_alloc(char **tbl, int i)
{
	if (!tbl)
	{
		tbl = (char **)malloc(sizeof(char *) * i);
		tbl[i] = ft_memalloc(BUFF_SIZE);
	}
	if (!tbl[i])
		tbl[i] = ft_memalloc(BUFF_SIZE);
	return (tbl);
}

int		get_next_line(const int fd, char **line)
{
	static char		**stock;
	int				i;


	i = 0;
	if (fd == 0)
		return (0);
	if (!stock || !stock[fd])
		stock = ft_alloc(stock, fd);
	*line = ft_memalloc(ft_strlen(stock[fd]) + BUFF_SIZE);
	if (ft_strlen(stock[fd]))
	{
		ft_strcpy(*line, stock[fd]);
		ft_strclr(stock[fd]);
	}
	while ((ret = read(fd, stock[fd], BUFF_SIZE)))
	{
		if (ret <= 0)
			return (ret == 0 ? 0 : -1);
		else
		{

			if (stock[fd][ret - 1] == '\n')
			{
				if (i = ft_intchr(stock[fd], '\n') < ret)
					ft_strlcat(*line, stock[fd], i + 1);
				else (i = ret)
					ft_strcpy(*line, stock[fd]);
				break ;
			}
			else
			{
				if (i = ft_intchr(stock[fd], '\n') < BUFF_SIZE)
					ft_strlcat(*line)
			}
	}
	while (i--)
	{
		stock[fd]++;
		while (*stock[fd] == '\n')
			stock[fd]++;
	}
	return (1);
}

//int		get_next_line(const int fd, char **line)
//{
//	static char		**stock;
//	int				i;
//	int				ret;
//
//
//	// assert line empty
//	if (line)
//		ft_strdel(line);
//
//	// check fake fd
//	i = 0;
//	if (fd == 0)
//		return (0);
//	
//	// assert stock[fd] to be allocated
//	if (!stock || !stock[fd])
//		stock = ft_alloc(stock, fd);
//
//
//	// 
//	*line = ft_memalloc(ft_strlen(stock[fd]) + BUFF_SIZE + 1);
//	if (ft_strlen(stock[fd]))
//	{
//		ft_strcpy(*line, stock[fd]);
//		ft_strclr(stock[fd]);
//	}
//
//	// cas pourris
//	if ((ret = read(fd, stock[fd], BUFF_SIZE)) <= 0)
//			return (ret == 0 ? 0 : -1);
//	ft_putchar('[');
//	ft_putstr(*line);
//	ft_putchar(']');
//	/*
//	** cas stock plus court que le line qu'on cherche :
//	** tant que pas de '\n' dans stock
//	**		stock->line
//	** 		read->stock
//	** cas stock egal au line qu'on cherche :
//	** 		stock->line
//	** cas stock superieur au line qu'on cherche :
//	**		stock jusqu'au '\n' -> line
//	**      stock apres le '\n' -> stock
//	** 
//	**	!! Si stock[fd][i = 0; i++] == '\n' !!
//	**
//	*/
//	// if ((i = ft_intchr(stock[fd], '\n')) < BUFF_SIZE)
//	// 		ft_strlcat(*line, stock[fd], i + 1);
//
//	while (i)
//	{
//		stock[fd]++;
//		i--;
//		while(*stock[fd] == '\n')
//			stock[fd]++;	
//	}
//	return (1);
//}
//