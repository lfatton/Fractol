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

int	main(int ac, char **av)
{
	t_env	e;
	t_img	img;
	t_point	p;

	e.img = &img;
	e.p = &p;
	if (ac != 2)
		error_fractol("usage: ./fractol fractal_name");
	if (!ft_strcmp(av[1], "mandelbrot"))
		e.fract = MANDEL;
	else if (!ft_strcmp(av[1], "julia"))
		e.fract = JULIA;
	else if (!ft_strcmp(av[1], "burningship"))
		e.fract = SHIP;
	else
		error_fractol("error: not a valid fractal name");
	init_fractol(&e, av[1]);
	return (0);
}
