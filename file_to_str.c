#include "fdf.h"

void	ft_strncpy(char *dst, char *src, size_t	n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}

void	read_ret_error_check(ssize_t	read_ret)
{
	if (read_ret == 0)
		exit(1);
}

ssize_t	read_and_check(int	fd, char *buf)
{
	ssize_t	ret;

	ret = read(fd, buf, 1);
	if (ret == -1)
		exit(1);
	return (ret);
}

char	*read_to_save(int fd, int stack_size, char *save)
{
	ssize_t	read_ret;
	char	buf[1];
	size_t	i;
	char	*new;

	read_ret = read_and_check(fd, buf);
	read_ret_error_check(read_ret);
	i = 0;
	while (read_ret)
	{
		if ((i % stack_size) == 0)
		{
			new = (char *)malloc(sizeof(char) * (i + stack_size + 1));
			if (!new)
				exit(1);
			ft_strncpy(new, save, i);
			free(save);
			save = new;
		}
		save[i] = *buf;
		i++;
		read_ret = read_and_check(fd, buf);
	}
	save[i] = '\0';
	return (save);
}

char	*file_to_str(char **argv)
{
	int		fd;
	int		stack_size;
	char	*save;

	fd = 0;
	stack_size = 50000;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	save = (char *)malloc(sizeof(char) * stack_size + 1);
	if (!save)
		exit(1);
	save = read_to_save(fd, stack_size, save);
	return (save);
}
