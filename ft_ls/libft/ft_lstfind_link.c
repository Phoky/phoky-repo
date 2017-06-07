/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:45:36 by rcolleau          #+#    #+#             */
/*   Updated: 2017/02/14 15:45:37 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_link(const t_list *lst, int n)
{
	t_list	*find_me;

	if (!lst)
		return (NULL);
	find_me = (t_list *)lst;
	while (find_me && (int)find_me->content_size != n)
		find_me = find_me->next;
	return (find_me);
}
