/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:18:24 by rcolleau          #+#    #+#             */
/*   Updated: 2016/12/13 19:28:45 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	new = NULL;
	start = NULL;
	start->next = new;
	while (lst != NULL)
	{
		if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new = f(lst);
		printf("content_size = %zu\n", new->content_size);
		if (lst->next == NULL)
			break ;
		else
		{
			lst = lst->next;
			new = new->next;
		}
	}
	new->next = NULL;
	return (start->next);
}

t_list    *lstmap_test_fn(t_list *list)
{
	t_list    *l2;
	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}
int     main(void)
{
	t_list    *list;
	t_list    *map;
	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
	list->content_size = 21;
	list->content = strdup("abc");
	list->next->content_size = 100;
	list->next->content = strdup("abc");
	map = ft_lstmap(list, lstmap_test_fn);
	printf("21 : %zu\n", list->content_size);
	printf("100: %zu\n", list->next->content_size);
	printf("42 : %zu\n", map->content_size);
	printf("200: %zu\n", map->next->content_size);
}
