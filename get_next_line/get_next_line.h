/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcolleau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:33:02 by rcolleau          #+#    #+#             */
/*   Updated: 2017/02/13 12:33:04 by rcolleau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 42

int		get_next_line(const int fd, char **line);

#endif
