#include "../get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>

int		main(void)
{
	int		fda;
	char	*line = NULL;
	int		res = 0;
	int		fdb;

	fda = open("aaa", O_RDONLY);
	if ((res = get_next_line(fda, &line)) > 0)
	{
		ft_putstr("[res = ");
		ft_putnbr(res);
		ft_putstr("]\n");
		ft_putendl(line);
	}
	close(fda);
	fdb = open("bbb", O_RDONLY);
	if ((res = get_next_line(fdb, &line)) > 0)
	{
		ft_putstr("[res = ");
		ft_putnbr(res);
		ft_putstr("]\n");
		ft_putendl(line);
	}
	fda = open("aaa", O_RDONLY);
	if ((res = get_next_line(fda, &line)) > 0)
	{
		ft_putstr("[res = ");
		ft_putnbr(res);
		ft_putstr("]\n");
		ft_putendl(line);
	}
	return (0);
}