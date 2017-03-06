#include "fdf.h"

int		find_biggest(int **tbl)
{
	int	i;
	int	j;
	int r;

	i = 0;
	j = 0;
	r = tbl[i][j];
	while (tbl[i])
	{
		while (tbl[i][j] != -1)
		{
			if (tbl[i][j] > r)
				r = tbl[i][j];
			j++;
		}
		i++;
	}
	return (r);
}