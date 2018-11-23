/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelblob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:18:23 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/23 17:34:05 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelblob(t_env *e, int x, int y)
{
	t_point	*p;
	int		i;

	p = (t_point*)malloc(sizeof(t_point));
	ft_memcpy(p, e->p, sizeof(t_point));
	get_coords(e, p, x, y);
	i = -1;
	while ((ft_pow(p->z_r) + ft_pow(p->z_i) <= 4) && ++i < e->img->i_max)
	{
		p->prev_z_r = p->z_r;
		p->prev_z_i = p->z_i;
		p->z_r = ft_pow(p->z_r) - ft_pow(p->z_i) + ft_pow(p->c_r);
		p->z_i = 2 * p->prev_z_r * p->prev_z_i + p->c_i;
	}
	e->img->str[x + y * WIN_W] = get_color(e->img->c, i, e->img->i_max);
	free(p);
}
