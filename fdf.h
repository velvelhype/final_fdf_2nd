#ifndef FDF_H
# define FDF_H
# define WIDTH 1000
# define HEIGHT 800
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_point
{
	int		height;
	int		color;
	float	x;
	float	y;
}	t_point;

typedef struct s_fdf
{
	int		x;
	int		y;
	int		is_threeD;
	float	rotation;
	t_point	**points;
	void	*mlx_ptr;
	void	*win_ptr;

	void	*image;
	char	*addr;
	int		pix_bits;
	int		line_len;
	int		endi;

	double	lean_x;
	double	lean_y;
	int		shift_x;
	int		shift_y;
	int		zoom;
}	t_fdf;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_color_step
{
	float	red;
	float	green;
	float	blue;
}	t_color_step;

char	*file_to_str(char **argv);
void	str_to_t_fdf(t_fdf *fdf, char *save);
int		count_axis(char	*save);
int		count_ordinary(char *save);
int		get_height(char *save, int *bookmark);
void	coordinate_point(t_fdf *fdf, t_point *a, t_point *b);
float	max(float a, float b);
float	mod(float val);
void	draw(t_fdf *fdf);
void	paint_it_black(t_fdf *fdf);
void	my_pixel_put(t_fdf *fdf, t_point dot_a);
float	make_color_step(int a_color, int b_color, int max);
void	printf_point_matrix(t_fdf *fdf);

#endif
