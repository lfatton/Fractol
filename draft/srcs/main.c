#include "fractol.h"

void    error_fractol(char *err)
{
        ft_putendl(err);
        exit(EXIT_FAILURE);
}

void    create_pix(t_env *e, int x, int y)
{
        int     pix;

        if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
                return ;
        pix = (x * e->bpp / 8) + (y * e->s_l);
        e->img_str[pix++] = (e->img->color) & 0x000000FF;
        e->img_str[pix++] = (e->img->color >> 8) & 0x000000FF;
        e->img_str[pix] = (e->img->color >> 16) & 0x000000FF;
}

int             deal_key(int key, t_env *e)
{
        if (key == ESC)
                quit_fractol(e);
        return (0);
}

void    print_image(t_env *e)
{
        mlx_key_hook(e->win_ptr, deal_key, e);
        e->img_ptr = mlx_new_image(e->mlx_ptr, WIN_W, WIN_H);
        e->img_str = mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->s_l),
                        &(e->endian));
        mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
        mlx_loop(e->mlx_ptr);
}

void	init_fractol(t_env *e, char *str)
{
	e->mlx_ptr = mlx_init();
       	e->win_ptr = mlx_new_window(e->mlx_ptr, WIN_W, WIN_H, str);
	print_image(e);
}

void	quit_fractol(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(EXIT_SUCCESS);
}

void	mandelbrot(t_env *e)
{
       	init_fractol(e, "Mandelbrot");
}

void	julia(t_env *e)
{
       	init_fractol(e, "Julia");
}

void	burning_ship(t_env *e)
{
	init_fractol(e, "Burning ship");
}

int             main(int ac, char **av)
{
        t_env   e;
	t_img	img;

        e.img = &img;
	if (ac != 2)
                error_fractol("usage: ./fractol fractal_name");
	if (!ft_strcmp(av[1], "mandelbrot"))
		mandelbrot(&e);
	else if (!ft_strcmp(av[1], "julia"))
		julia(&e);
	else if (!ft_strcmp(av[1], "burningship"))
		burning_ship(&e);
	else
		error_fractol("error: not a valid fractal name");
        return (0);
}
