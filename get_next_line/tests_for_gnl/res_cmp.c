#include "../get_next_line.c"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stats.h>

int		main(void)
{
	FILE *f1;
	FILE *f2;
	f1 = fopen("res1", "w");
	f2 = fopen("res2", "w");
	
	int	fd1 = open("Star_Wars_1.txt", O_RDONLY);
	int fd2 = open("Star_Wars_2.txt", O_RDONLY);
	int	res1 = open("res1", O_WRONLY);
	int res2 = open("res2", O_WRONLY);
	char *line1 = NULL;
	char *line2 = "il etait une fois";

	while (get_next_line(fd1, &line1))
		ft_putendl_fd(line1, res1);
	while (get_next_line(fd2, &line2))
		ft_putendl_fd(line2, res2);
	if (((ft_filecmp("res1", "Star_Wars_1.txt")) > 0) || (ft_filecmp("res2", "Star_Wars_2.txt") > 0))
		ft_putendl("Error");
	return (0);
}