/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:15:40 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 21:33:48 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e)
{
	int		y;
	int		x;
	int		i;
	double	tmp;

	y = 0;
	while (y < IMG_H)
	{
		x = 0;
		while (x < IMG_W)
		{
			e->p->c_r = (x - IMG_W / 2.0) * e->img->zoom / IMG_W;
			e->p->c_i = (y - IMG_H / 2.0) * e->img->zoom / IMG_W;
			e->p->z_r = 0;
			e->p->z_i = 0;
			i = 0;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i <= 4) && i < ITER_MAX)
			{
				tmp = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->c_r;
				e->p->z_i = 2 * e->p->z_r * e->p->z_i + e->p->c_i;
				e->p->z_r = tmp;
				i++;
			}
			if (i < ITER_MAX)
				create_pix(e, x, y, get_color(i));
			else
				create_pix(e, x, y, BLACK);
			x++;
		}
		y++;
	}
}
