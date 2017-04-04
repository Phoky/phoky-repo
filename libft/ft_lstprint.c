#include "libft.h"

//void	ft_lstprint_int(t_val *alst)
//{
//	t_val	*tmp;
//
//	tmp = alst;
//	while (tmp)
//	{
//		while (tmp->content != -1)
//		{
//			ft_putnbr(tmp->content);
//			tmp->content++;
//		}
//		tmp = tmp->next;
//	}
//}

void	ft_lstprint(t_list *alst)
{
	t_list	*tmp;

	tmp = alst;
	while (tmp)
	{
		ft_puttbl(tmp->content);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}