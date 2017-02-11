#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		res;
//	int		f;
//	int		c;

	if (argc && argv[0])
		res = 0;
/*	fd = open("texte.txt", O_RDONLY);
**	printf("%d\n", fd);
**
**	if (res = get_next_line(fd, &line) > 0)
**	{
**		printf("%d\n", res);
**		printf("%s\n", line);
**	}
**
**	fd = open("truc.txt", O_RDONLY);
**	printf("%d\n", fd);
**
**	if (res = get_next_line(fd, &line) > 0)
**	{
**		printf("%d\n", res);
**		printf("%s\n", line);
**	}
*/
	fd = open("machin.txt", O_RDONLY);
//
//	f = open("a", O_RDONLY);
//	c = open("texte.txt", O_RDONLY);
//	int	u = open("res1", O_WRONLY);
//	int	v = open("res2", O_WRONLY);
//	int	w = open("res3", O_WRONLY);
//	res = 1;
	while ((res = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(res);
		ft_putstr("\t");
		ft_putstr(line);
		sleep (1);
	}
//	while (res)
//	{
//		res = get_next_line(fd, &line);
//		ft_putnbr(res);
//		ft_putchar('-');
//		ft_putnbr(fd);
//		ft_putchar('\t');
//		ft_putendl_fd(line, u);
//		res = get_next_line(f, &line);
//		ft_putnbr(res);
//		ft_putchar('-');
//		ft_putnbr(f);
//		ft_putchar('\t');
//		ft_putendl_fd(line, v);
//		res = get_next_line(c, &line);
//		ft_putnbr(res);
//		ft_putchar('-');
//		ft_putnbr(c);
//		ft_putchar('\t');
//		ft_putendl_fd(line, w);
//	}
//	res = get_next_line(fd, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(fd);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(f, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(f);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(c, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(c);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(fd, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(fd);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(f, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(f);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(c, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(c);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(fd, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(fd);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(f, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(f);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(c, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(c);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(fd, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(fd);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(f, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(f);
//	ft_putchar('\t');
//	ft_putendl(line);
//	res = get_next_line(c, &line);
//	ft_putnbr(res);
//	ft_putchar('-');
//	ft_putnbr(c);
//	ft_putchar('\t');
//	ft_putendl(line);


	return (0);
}
