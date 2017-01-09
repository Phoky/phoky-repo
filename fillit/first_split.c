#include "fillit.h"

int		check_tbl(char **tbl)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	j = 0;
	c = 'A';
	while(tbl[i])
	{
		if (tbl[i][0] == '\n')
			return (0);
		while (tbl[i][j])
		{
			if (tbl[i][j] == '#')
				tbl[i][j] = c;
			j++;
		}
		i++;
		j = 0;
		c++;
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
