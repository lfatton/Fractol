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
	double	prev_z_r;
	double	prev_z_i;

	while (++e->p->y < WIN_H)
	{
		e->p->x = -1;
		while (++e->p->x < WIN_W)
		{
			e->p->z_r = (e->p->x + e->w) / e->img->zoom;
			e->p->z_i = (e->p->y + e->h) / e->img->zoom;
			i = -1;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i <= 4) && ++i
					< e->img->i_max)
			{
				prev_z_r = e->p->z_r;
				prev_z_i = e->p->z_i;
				tmp = prev_z_r * prev_z_r - prev_z_i * prev_z_i + e->p->k_r;
				e->p->z_i = 2 * prev_z_r * prev_z_i + e->p->k_i;
				e->p->z_r = tmp;
			}
			create_pix(e, get_color(e, i));
		}
	}
}
