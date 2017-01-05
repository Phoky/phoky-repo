#ifndef _FILLIT_H
#define _FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

#define BUF_SIZE 39

//typedef struct		s_list
//{
//	struct s_list	*prev;
//	char			**tetri;
//	struct s_list	*next;
//}					t_list

char	*ft_open_file(char *str);
int		main(int argc, char **argv);
char	**first_split(char *str);

#endif