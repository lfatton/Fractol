/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:09:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 19:47:42 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int             main(int ac, char **av)
{
    t_env   e;
	t_img	img;
	t_point	p;

    e.img = &img;
	e.p = &p;
	if (ac != 2)
                error_fractol("usage: ./fractol fractal_name");
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		init_fractol(&e, av[1], 1);
	}
	else if (!ft_strcmp(av[1], "julia"))
		init_fractol(&e, av[1], 2);
	else if (!ft_strcmp(av[1], "burningship"))
		init_fractol(&e, av[1], 3);
	else
		error_fractol("error: not a valid fractal name");
        return (0);
}
