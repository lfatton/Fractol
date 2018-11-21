/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:15:40 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/21 22:38:47 by lfatton          ###   ########.fr       */
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
	double	c_r = x / e->img->zoom + e->w;
	double	c_i =  y / e->img->zoom + e->h;
	double	z_r = 0;
	double	z_i = 0;

	i = -1;
	//get_coords(e, x, y);
	double z_r2 = z_r * z_r;
	double z_i2 = z_i * z_i;
			while ((z_r2 + z_i2 <= 4) && ++i < e->img->i_max)
			{
				z_i = z_r * z_i;
				z_i += z_i;
				z_i += c_i;
				z_r = z_r2 - z_i2 + c_r;
	z_r2 = z_r * z_r;
	z_i2 = z_i * z_i;
			}
			/*while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				e->p->z_i = e->p->z_r * e->p->z_i;
				e->p->z_i += e->p->z_i;
				e->p->z_i += e->p->c_i;
				e->p->z_r = e->p->z_r2 - e->p->z_i2 + e->p->c_r;
				pow_coords(e);
			}*/
			e->img->pix[x + y * WIN_W] = i;
}
