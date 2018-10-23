/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:59 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/21 18:56:58 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_env *e)
{
	int		i;
	double	tmp;

	while (++e->p->y < WIN_H)
	{
		e->p->x = -1;
		while (++e->p->x < WIN_W)
		{
			e->p->c_r = (e->p->x + e->w) / e->img->zoom;
			e->p->c_i = (e->p->y + e->h) / e->img->zoom;
			e->p->z_r = 0;
			e->p->z_i = 0;
			i = -1;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i <= 4) && ++i
					< e->img->i_max)
			{
				tmp = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->c_r;
				e->p->z_i = ft_dabs(2 * e->p->z_r * e->p->z_i) + e->p->c_i;
				e->p->z_r = tmp;
			}
			create_pix(e, get_color(e, i));
		}
	}

}
