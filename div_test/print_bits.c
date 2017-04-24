#include "libft/libft.h"

void	print_bits(unsigned char octet)
{
	ft_putnbrendl(octet);
	int t[8];
	int	i;
	int	r;

	r = octet;
	i = 7;
	while (r)
	{
		t[i] = r % 2;
		r /= 2;
		i--;
	}
	if (i != 0)
	{
		while (i > 0)
		{
			t[i] = 0;
			i--;
		}
	}
	while (i <= 7)
	{
		ft_putnbr(t[i]);
		i++;
	}
}

int		main(void)
{
	unsigned char a;

	a = 0;
	ft_putnbrendl((int)a);
	while (a < 255)
	{
		print_bits(a);
		ft_putchar('\n');
		a++;
	}
	return (0);
}