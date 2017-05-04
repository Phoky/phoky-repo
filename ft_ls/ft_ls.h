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

typedef struct 		s_arg
{
	int				l;
	int				upper_r;
	int				lower_r;
	int				upper_a;
	int				lower_a;
	int				t;
	int				upper_g;
	int				u;
	int				upper_F;
}					t_arg;

int				main(int argc, char **argv);

#endif