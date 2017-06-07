/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:18:24 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/14 17:40:51 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	start = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		new = f(new);
		if (!start)
			start = new;
		else
			ft_lstadd_end(&start, new);
		lst = lst->next;
	}
	return (start);
}
