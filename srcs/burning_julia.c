/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:21:31 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 19:13:17 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_julia(t_env *e, int x, int y)
{
	int		i;
	
		e->p->x = -1;
		i = -1;
			get_coords(e, x, y);
			while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				e->p->prev_z_r = e->p->z_r;
				e->p->prev_z_i = e->p->z_i;
				e->p->z_i = ft_dabs(2 * e->p->prev_z_r * e->p->prev_z_i) + e->p->k_i;
				e->p->z_r = e->p->z_r2 - e->p->z_i2 + e->p->k_r;
				pow_coords(e);
			}
			e->img_str[x + (y * WIN_W)] = get_color(e, i);
}
