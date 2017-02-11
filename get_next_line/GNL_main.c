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
	int		f;
	int		c;

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
	f = open("a", O_RDONLY);
	c = open("texte.txt", O_RDONLY);
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
//	close(c);
//	c = open("res", O_RDWR);
	while ((res = get_next_line(c, &line) > 0))
	{
		ft_putnbr(res);
//		printf("[line = %s]\n\n", line);
		ft_putstr("\t");
//		ft_putstr_fd(line, c);
//		ft_putendl_fd("\n", f);
		ft_putendl(line);
//		ft_putstr("]\n");
//		printf("%s\n", line);
	}
	return (0);
}
