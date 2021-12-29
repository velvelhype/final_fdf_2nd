#include "fdf.h"

void	put_pix(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->pix_bits / 8));
		*(unsigned int *)dst = color;
	}
}

void	paint_it_black(t_fdf *fdf)
{
	int		color;
	int		x;
	int		y;

	color = 0x000000;
	x = 0;
	y = 0;
	while (y <= HEIGHT)
	{
		while (x <= WIDTH)
		{
			put_pix(fdf, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	my_pixel_put(t_fdf *fdf, t_point dot_a)
{
	if (dot_a.x < 0 || dot_a.x > WIDTH)
		return ;
	if (dot_a.y < 0 || dot_a.y > HEIGHT)
		return ;
	put_pix(fdf, (int)dot_a.x, (int)dot_a.y, dot_a.color);
}
