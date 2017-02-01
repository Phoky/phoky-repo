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
	fd = open("a", O_RDONLY);
	while ((res = get_next_line(fd, &line) > 0))
	{
//		printf("[res = %d]\n", res);
		printf("[line = %s]\n", line);
//		printf("%s\n", line);
	}

	return (0);
}
