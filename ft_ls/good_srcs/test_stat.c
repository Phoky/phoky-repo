# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>

void	print_stat(struct stat *st)
{
	ft_putstr("dev = ");
	ft_putnbrendl(st->st_dev);
	ft_putstr("mode = ");
	ft_putnbrendl(st->st_mode);
	ft_putstr("nlink = ");
	ft_putnbrendl(st->st_nlink);
	ft_putstr("ino = ");
	ft_putnbrendl(st->st_ino);
	ft_putstr("uid = ");
	ft_putnbrendl(st->st_uid);
	ft_putstr("gid = ");
	ft_putnbrendl(st->st_gid);
	ft_putstr("rdev = ");
	ft_putnbrendl(st->st_rdev);
//	ft_putstr("atime = ");
//	ft_putnbrendl(st->st_atimespec);
//	ft_putstr("mtime = ");
//	ft_putnbrendl(st->st_mtimespec);
//	ft_putstr("birthtime = ");
//	ft_putnbrendl(st->st_birthtimespec);
	ft_putstr("size = ");
	ft_putnbrendl(st->st_size);
	ft_putstr("blocks = ");
	ft_putnbrendl(st->st_blocks);
	ft_putstr("blksize = ");
	ft_putnbrendl(st->st_blksize);
	ft_putstr("flags = ");
	ft_putnbrendl(st->st_flags);
	ft_putstr("gen = ");
	ft_putnbrendl(st->st_gen);
	ft_putstr("lspare = ");
	ft_putnbrendl(st->st_lspare);
	ft_putstr("qspare[0] = ");
	ft_putnbrendl(st->st_qspare[0]);
	ft_putstr("qspare[1] = ");
	ft_putnbrendl(st->st_qspare[1]);
}

int		main(int argc, char **argv)
{
	int			i;
	struct stat	st;
	time_t		ti;

	i = 1;
	while (argv[i])
	{
		lstat(argv[i], &st);
		ti = time((time_t)st.st_atimespec);
		ft_put_two_arg(argv[i], " :", 1);
		print_stat(&st);
		ft_putendl("\n");
		i++;
	}
	return (0);
}