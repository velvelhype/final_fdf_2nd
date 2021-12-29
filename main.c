#include "fdf.h"

int	deal_key(int key, t_fdf *fdf)
{
	if (key == 51)
		fdf->is_threeD = 1;
	if (key == 50)
		fdf->is_threeD = 0;
	if (key == 114)
		fdf->rotation += 0.03;
	if (key == 101)
		fdf->rotation -= 0.03;
	if (key == 61)
		fdf->zoom += 1;
	if (key == 45)
		fdf->zoom -= 1;
	if (key == 65362)
		fdf->shift_y -= 40;
	if (key == 65364)
		fdf->shift_y += 40;
	if (key == 65361)
		fdf->shift_x -= 40;
	if (key == 65363)
		fdf->shift_x += 40;
	if (key == 65307)
		exit(0);
	draw(fdf);
	return (0);
}

void	init_fdf(t_fdf *f)
{
	char	*a;

	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "fdf");
	f->image = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	a = mlx_get_data_addr(f->image, &(f->pix_bits), &(f->line_len), &(f->endi));
	f->addr = a;
	f->is_threeD = 1;
	f->rotation = 1.047;
	f->shift_x = WIDTH / 2;
	f->shift_y = HEIGHT / 2;
	f->zoom = 10;
}

int	main(int argc, char **argv)
{
	char	*save;
	t_fdf	fdf;

	if (argc != 2)
		exit(1);
	save = file_to_str(argv);
	init_fdf(&fdf);
	str_to_t_fdf(&fdf, save);
	draw(&fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, deal_key, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
