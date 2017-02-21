#include "../get_next_line.h"

int		main(void)
{
	char *line = NULL;
	int	res;
	int fd = open("texte.txt", O_RDONLY);
	
	while ((res = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(res);
		ft_putstr("\t");
		ft_putendl(line);
	}
	while (1)
		;
	close(fd);
	return (0);
}
