/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_crea.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 11:57:00 by rcolleau          #+#    #+#             */
/*   Updated: 2017/04/02 12:10:05 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int key, void *param, void *param1)
{
	if (param && param1)
	{
		if (key == 53)
		{
			free(param);
			free(param1);
			exit(1);
		}
	}
	return (key);
}

int		*find_biggest(int **t, t_val *ch)
{
	t_val	*temp;

	t[0] = (int *)malloc(sizeof(int) * 2);
	t[0][0] = 0;
	t[0][1] = 0;
	temp = ch;
	while (temp)
	{
		if (temp->value > t[0][0])
			t[0][0] = temp->value;
		if (temp->y > t[0][1])
			t[0][1] = temp->y;
		if (temp->x > t[0][1])
			t[0][1] = temp->x;
		temp = temp->next;
	}
	t[0][0] += 1;
	t[0][1] += 1;
	free(temp);
	return (t[0]);
}

void	window_crea(t_val **chain)
{
	t_val	*tmp;
	void	*mlx;
	void	*win;
	int		*co;

	tmp = *chain;
	co = find_biggest(&co, *chain);
	mlx = mlx_init();
//	ft_putstr("co[0] = ");
//	ft_putnbrendl(co[0]);
//	ft_putstr("co[1] = ");
//	ft_putnbrendl(co[1]);
	win = mlx_new_window(mlx, (co[1] * 10), (co[0] * 10), "fdf");
//	ft_putstr("co[0] = ");
//	ft_putnbrendl(co[1] * 10);
//	ft_putstr("co[1] = ");
//	ft_putnbrendl(co[0] * 10);
	while (tmp)
	{
		if (tmp->color)
			mlx_pixel_put(mlx, win, (tmp->x + 1) * 10, (tmp->y + 1) * tmp->value, (int)tmp->color);
		else
			mlx_pixel_put(mlx, win, (tmp->x + 1) * 10, (tmp->y + 1) * tmp->value, WHITE);
		tmp = tmp->next;
	}
	mlx_key_hook(win, my_key_func, mlx);
	mlx_mouse_hook(win, my_key_func, mlx);
	mlx_loop(mlx);
}
