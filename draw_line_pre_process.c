#include "fdf.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}

void	make_isometric(t_point *dot, t_fdf *fdf)
{
	dot->x = (dot->x - dot->y) * cos(fdf->rotation);
	dot->y = (dot->x + dot->y) * sin(fdf->rotation) - dot->height;
}

void	coordinate_point(t_fdf *fdf, t_point *a, t_point *b)
{
	a->x *= fdf->zoom;
	b->x *= fdf->zoom;
	a->y *= fdf->zoom;
	b->y *= fdf->zoom;
	a->height *= fdf->zoom;
	b->height *= fdf->zoom;
	if (fdf->is_threeD)
	{
		make_isometric(a, fdf);
		make_isometric(b, fdf);
	}
	a->x += fdf->shift_x;
	b->x += fdf->shift_x;
	a->y += fdf->shift_y;
	b->y += fdf->shift_y;
}
