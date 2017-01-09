#include "fillit.h"

void	printtbl(char ***tbl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
//	printf("BONJOUR\n");
//	while (tbl[i])
//	{
		printf("BONJOUR");
		while (tbl[i][j])
		{
			ft_putstr(tbl[i][j]);
			j++;
		}
//		i++;
//		j = 0;
//	}
}

int	tbllen(char **tbl)
{
	int	i;

	i = 0;
	while (*tbl)
	{
		i++;
		tbl++;
	}
	return (i);
}

char	***final_split(char **tbl)
{
	char	***tf;
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
	if ((tf = (char ***)malloc(sizeof(char **) * (tbllen(tbl)))) == NULL)
		return (NULL);
	while (*tf)
	{
		*tf = ft_strsplit(*tbl, '\n');
		tf++;
		tbl++;
	}
	printtbl(tf);
	return (tf);
}
