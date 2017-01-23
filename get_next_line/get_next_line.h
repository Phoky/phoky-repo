#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif