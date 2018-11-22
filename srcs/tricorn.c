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
	t_point		*p;
	int		i;

	p = (t_point*)malloc(sizeof(t_point));
        ft_memcpy(p, e->p, sizeof(t_point));
	get_coords(e, p, x, y);
	i = -1;
	while ((p->z_r2 + p->z_i2 <= 4) && ++i < e->img->i_max)
	{
		p->z_i = -(p->z_r * p->z_i) * 2 + p->c_i;
		p->z_r = p->z_r2 - p->z_i2 + p->c_r;
		pow_coords(p);
	}
	e->img->str[x + y * WIN_W] = get_color(e, i);
	free(p);
}

