/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:18 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 20:01:43 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_env *e)
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
			e->p->k_r = 0.353 * e->img->zoom / IMG_W;
			e->p->k_i = 0.288 * e->img->zoom / IMG_W;
			e->p->z_r = 0;
			e->p->z_i = 0;
			i = 0;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i <= 4) && i < ITER_MAX)
			{
				tmp = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->k_r;
				e->p->z_i = 2 * e->p->z_r * e->p->z_i + e->p->k_i;
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
