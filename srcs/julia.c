/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:18 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 15:56:44 by lfatton          ###   ########.fr       */
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
			i = -1;
			get_coords(e);
			while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				pow_coords(e);
				prev_z_r = e->p->z_r;
				prev_z_i = e->p->z_i;
				tmp = e->p->z_r2 - e->p->z_i2 + e->p->k_r;
				e->p->z_i = 2 * prev_z_r * prev_z_i + e->p->k_i;
				e->p->z_r = tmp;
			}
			e->img_str[e->p->x + (e->p->y * WIN_W)] = get_color(e, i);
		}
	}
}
