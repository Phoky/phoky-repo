#ifndef _FT_LS_H
# define _FT_LS_H

typedef struct		s_bla
{
	ino_t			ino;
	off_t			off;
	unsigned short	reclen;
	unsigned char	type;
	char			*name;
	struct s_bla	*next;
}					t_bla;

int				main(int argc, char **argv);

#endif