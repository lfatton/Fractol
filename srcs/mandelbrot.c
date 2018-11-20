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

void	mandelbrot(t_env *e, int x, int y)
{
	int		i;
			i = -1;
			e->p->z_r = 0;
                 e->p->z_i = 0;
                 e->p->c_r = x / e->img->zoom + e->w;
                 e->p->c_i = y / e->img->zoom + e->h;
e->p->z_r2 = e->p->z_r * e->p->z_r;
        e->p->z_i2 = e->p->z_i * e->p->z_i;
			while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				e->p->z_i = e->p->z_r * e->p->z_i;
				e->p->z_i += e->p->z_i;
				e->p->z_i += e->p->c_i;
				e->p->z_r = e->p->z_r2 - e->p->z_i2 + e->p->c_r;
				pow_coords(e);
			}
			e->img_str[y * WIN_W + x] = get_color(e, i);
}
