#include "fdf.h"

int	rated_color(int start, int end, double rate)
{
	return ((int)((1 - rate) * start + rate * end));
}

int	pt_col(int cur_col, int ini_col, int end_col, double rate)
{
	int		red;
	int		green;
	int		blue;

	if (cur_col == end_col)
		return (cur_col);
	red = rated_color((ini_col >> 16) & 0xFF, (end_col >> 16) & 0xFF, rate);
	green = rated_color((ini_col >> 8) & 0xFF, (end_col >> 8) & 0xFF, rate);
	blue = rated_color(ini_col & 0xFF, end_col & 0xFF, rate);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	int		max_s;
	float	x_step;
	float	y_step;
	int		init_col;
	int		cnt;

	coordinate_point(fdf, &a, &b);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max_s = max(mod(x_step), mod(y_step));
	x_step /= max_s;
	y_step /= max_s;
	init_col = a.color;
	cnt = 0;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_pixel_put(fdf, a);
		cnt++;
		a.x += x_step;
		a.y += y_step;
		a.color = pt_col(a.color, init_col, b.color, (float)cnt / (float)max_s);
	}
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	paint_it_black(fdf);
	while (y < fdf->y)
	{
		while (x < fdf->x)
		{
			if (x < fdf->x - 1)
				draw_line(fdf, fdf->points[y][x], fdf->points[y][x + 1]);
			if (y < fdf->y - 1)
				draw_line(fdf, fdf->points[y][x], fdf->points[y + 1][x]);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->image, 0, 0);
}
