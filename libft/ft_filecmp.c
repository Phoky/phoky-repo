/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:41:57 by rcolleau          #+#    #+#             */
/*   Updated: 2017/01/27 12:42:00 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_filecmp(char *arg1, char *arg2)
{
	char *s;
	char *s1;

	s = open_file(arg1);
	s1 = open_file(arg2);
	return (ft_strcmp(s, s1));
}
