int		*ft_intline_crea(char *s)
{
	int	*line;
	int	i;

	line = (int *)malloc(sizeof(int) * ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if (isdigit(s[i]) == 1)
			line[i] = ft_atoi(s[i]);
		else
		{
			if (s[i] == '-')
			{
				ft_atoi()
			}
		}
	}

}


int		**ft_inttbl(char **tbl)
{
	int	**tab;

	tab = ft_memalloc(ft_tbllen(tbl));

}