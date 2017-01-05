#include "fillit.h"

int		check_tbl(char **tbl)
{
	while(*tbl)
	{
		if (**tbl == '\n')
			return (0);
//		ft_putstr(*tbl);
		printf("s = %s", *tbl);
		tbl++;
	}
	return (1);
}

char	**first_split(char *str)
{
	int		i;
	int		r;
	char	**tbl;

	i = 0;
	r = 20;
	tbl = NULL;
	while (str[i] != '\0')
	{
		 if (i == r && str[i] == '\n')
		 {
		 	str[i] = '1';
		 	r += 21;
		 }
		 i++;
	}
	tbl = ft_strsplit(str, '1');
	if (check_tbl(tbl) == 0)
		*tbl = "ERROR";
	return (tbl);
}