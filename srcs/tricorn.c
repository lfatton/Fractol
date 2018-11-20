/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:07:30 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/08 17:10:57 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn(t_env *e, int x, int y)
{
	int		i;

			i = -1;
			get_coords(e, x, y);
			while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				e->p->z_i = -(e->p->z_r * e->p->z_i);
				e->p->z_i += e->p->z_i;
				e->p->z_i += e->p->c_i;
				e->p->z_r = e->p->z_r2 - e->p->z_i2 + e->p->c_r;
				pow_coords(e);
		}	
			e->img_str[x + (y * WIN_W)] = get_color(e, i);
}

