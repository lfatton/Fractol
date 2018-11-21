/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:15:40 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 15:59:47 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_pixel(t_env *e, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	e->img->str[y * WIN_W + x] = color;
}

void	mandelbrot(t_env *e, int x, int y)
{
	int		i;
			i = -1;
	get_coords(e, x, y);
			while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				e->p->z_i = e->p->z_r * e->p->z_i;
				e->p->z_i += e->p->z_i;
				e->p->z_i += e->p->c_i;
				e->p->z_r = e->p->z_r2 - e->p->z_i2 + e->p->c_r;
				pow_coords(e);
			}
			//e->img->str[y * WIN_W + x] = get_color(e, i);
			create_pixel(e, x, y, get_color(e, i));
}
