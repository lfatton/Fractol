/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:18 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/22 22:49:27 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	brain(t_env *e, int x, int y)
{
	t_point	*p;
	int		i;

	p = (t_point*)malloc(sizeof(t_point));
	ft_memcpy(p, e->p, sizeof(t_point));
	get_coords(e, p, x, y);
	i = -1;
	while ((p->z_r2 + p->z_i2 <= 4) && ++i < e->img->i_max)
	{
		p->z_i = (p->z_i > 0 ? -p->z_i : p->z_i);
		p->prev_z_r = p->z_r;
		p->prev_z_i = p->z_i;
		p->z_i = 2 * p->prev_z_r * p->prev_z_i + p->k_i;
		p->z_r = p->z_r2 - p->z_i2 + p->k_r;
		pow_coords(p);
	}
	e->img->str[x + y * WIN_W] = get_color(e->img->c, i, e->img->i_max);
	free(p);
}
