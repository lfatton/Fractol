/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:09:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/19 22:08:11 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_fractal_name(t_env *e, char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		e->fract = MANDEL;
	else if (!ft_strcmp(str, "julia"))
		e->fract = JULIA;
	else if (!ft_strcmp(str, "burning_ship"))
		e->fract = SHIP;
	else if (!ft_strcmp(str, "sierpinsky_triangle"))
		e->fract = TRI;
	else
		return (0);
	return (e->fract);
}

int	main(int ac, char **av)
{
	t_env	e;
	t_img	img;
	t_point	p;

	e.img = &img;
	e.p = &p;
	if (ac != 2 || !get_fractal_name(&e, av[1]))
		error_fractol("usage: ./fractol [mandelbrot/julia/burning_ship/sierpinsky_triangle]");
	init_fractol(&e, av[1]);
	return (0);
}
