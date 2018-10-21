/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:18 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/19 22:38:25 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_env *e)
{
	int		i;
	double	tmp;

	e->p->y = -1;
	while (++e->p->y < IMG_H)
	{
		e->p->x = -1;
		while (++e->p->x < IMG_W)
		{
			e->p->z_r = (e->p->x - IMG_W / 2.0) * (e->img->zoom / IMG_W);
			e->p->z_i = (e->p->y - IMG_H / 2.0) * (e->img->zoom / IMG_W);
			i = -1;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i <= 4) && ++i
					< ITER_MAX)
			{
				tmp = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->k_r;
				e->p->z_i = 2 * e->p->z_r * e->p->z_i + e->p->k_i;
				e->p->z_r = tmp;
			}
			i < ITER_MAX ? create_pix(e, get_color(i)) : create_pix(e, BLACK);
		}
	}
}
