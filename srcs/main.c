/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:09:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/15 14:18:08 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
