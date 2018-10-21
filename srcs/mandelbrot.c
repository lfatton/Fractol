/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:15:40 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/19 22:37:18 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e)
{
	int		i;
	double	tmp;

	e->p->y = -1;
	while (++e->p->y < IMG_H)
	{
		e->p->x = -1;
		while (++e->p->x < IMG_W)
		{
			e->p->c_r = (e->p->x - IMG_W / 2.0) * (e->img->zoom / IMG_W);
			e->p->c_i = (e->p->y - IMG_H / 2.0) * (e->img->zoom / IMG_W);
			e->p->z_r = 0;
			e->p->z_i = 0;
			i = -1;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i <= 4) && ++i
					< ITER_MAX)
			{
				tmp = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->c_r;
				e->p->z_i = 2 * e->p->z_r * e->p->z_i + e->p->c_i;
				e->p->z_r = tmp;
			}
			i < ITER_MAX ? create_pix(e, get_color(i)) : create_pix(e, BLACK);
		}
	}
}
