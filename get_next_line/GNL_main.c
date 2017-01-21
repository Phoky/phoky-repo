#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		res;

	void(argc);
	res = 0;
	fd = open("/dev/random", O_RDONLY);
	while ((res = get_next_line(fd, &line) > 0))
	{
		printf("%d\n", res);
		printf("%s\n", line);
	}
	return (0);
}