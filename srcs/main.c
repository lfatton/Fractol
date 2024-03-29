/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:09:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/29 19:05:39 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_fractal_name(t_env *e, char *str)
{
	if ((!ft_strcmp(str, "mandelbrot")) && (e->fract = MANDEL))
		e->fract_funct = &mandelbrot;
	else if ((!ft_strcmp(str, "julia")) && (e->fract = JULIA))
		e->fract_funct = &julia;
	else if ((!ft_strcmp(str, "burning_ship")) && (e->fract = SHIP))
		e->fract_funct = &burning_ship;
	else if ((!ft_strcmp(str, "burning_julia")) && (e->fract = BJULIA))
		e->fract_funct = &burning_julia;
	else if ((!ft_strcmp(str, "tricorn")) && (e->fract = TRI))
		e->fract_funct = &tricorn;
	else if ((!ft_strcmp(str, "brain")) && (e->fract = BRAIN))
		e->fract_funct = &brain;
	else if ((!ft_strcmp(str, "mandelblob")) && (e->fract = BLOB))
		e->fract_funct = &mandelblob;
	else if ((!ft_strcmp(str, "frog")) && (e->fract = FROG))
		e->fract_funct = &frog;
	else
		return (0);
	return (e->fract);
}

int			main(int ac, char **av)
{
	t_env	*e;

	if	(!(e = (t_env*)malloc(sizeof(t_env))))
		error_fractol("error: cannot allocate memory");
	if (!(e->img = (t_img*)malloc(sizeof(t_img))))
		error_fractol("error: cannot allocate memory");
	if (!(e->p = (t_point*)malloc(sizeof(t_point))))
		error_fractol("error: cannot allocate memory");
	if (ac != 2 || !get_fractal_name(e, av[1]))
		error_fractol("usage: ./fractol [mandelbrot/julia/burning_ship"
				"/burning_julia/tricorn/brain/mandelblob/frog]");
	init_fractol(e, av[1]);
	mlx_expose_hook(e->win_ptr, expose_hook, e);
	mlx_hook(e->win_ptr, 2, 5, key_hook, e);
	mlx_hook(e->win_ptr, 4, 1L << 2, mouse_hook, e);
	mlx_hook(e->win_ptr, 6, 1L << 6, mouse_motion, e);
	mlx_hook(e->win_ptr, 17, 1L << 17, quit_fractol, e);
	mlx_loop(e->mlx_ptr);
	pthread_exit(NULL);
	return (EXIT_SUCCESS);
}
