/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:02:19 by rcolleau          #+#    #+#             */
/*   Updated: 2017/05/05 11:02:21 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
