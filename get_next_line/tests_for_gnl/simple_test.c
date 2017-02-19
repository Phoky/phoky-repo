#include "get_next_line.h"

int		main(void)
{
	int fd = open("texte.txt", O_RDONLY);
	while ((res = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(res);
		ft_putstr("\t");
		ft_putendl(line);
	}
	close(fd);
	return (0);
}
