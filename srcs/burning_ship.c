/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:59 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 16:01:14 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(void *env)
{
	int		i;

	t_env           *e;

	e = (t_env*)env;
	while (++e->p->y < WIN_H)
	{
		e->p->x = -1;
		while (++e->p->x < WIN_W)
		{
			i = -1;
			get_coords(e);
			while ((e->p->z_r2 + e->p->z_i2 <= 4) && ++i < e->img->i_max)
			{
				e->p->z_i = ft_dabs(2 * e->p->z_r * e->p->z_i) + e->p->c_i;
				e->p->z_r = e->p->z_r2 - e->p->z_i2 + e->p->c_r;
				pow_coords(e);
			}
			e->img_str[e->p->x + (e->p->y * WIN_W)] = get_color(e, i);
		}
	}
}
