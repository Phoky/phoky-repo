#include "fdf.h"

int		error_func(char *s)
{
	ft_putendl (s);
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tbl
	int		**tab;

	if (argc != 2)
		return (error_func("usage: ./fdf <filename>"));
	if ((tbl = ft_strsplit(ft_open_file(argv[1], '\n'))) == NULL)
		return (error_func("read error"));
	if ((tab = ft_inttbl(tbl)) == 0)
		return (error_func("file error"));
}