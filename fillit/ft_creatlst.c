#include "fillit.h"

int		check_tbl(char **tbl)
{
	int	i;

	i = 0;
	while(tbl[i])
	{
		if (tbl[i][0] == '\n')
			return (0);
		ft_putstr(tbl[i]);
		i++;
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
