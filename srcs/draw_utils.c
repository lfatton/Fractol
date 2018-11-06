/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:02:36 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/13 19:16:36 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_get_color_grad(int z)
{
	if (z <= -53)
		return (0x001122);
	else if (z <= -43)
		return (0x002244);
	else if (z <= -33)
		return (0x003366);
	else if (z <= -23)
		return (0x004D99);
	else if (z <= -13)
		return (0x005EBB);
	else if (z <= -3)
		return (0x0066CC);
	else if (z <= 3)
		return (0x11840A);
	else if (z <= 13)
		return (0x509823);
	else if (z <= 23)
		return (0x8EAD42);
	else if (z <= 33)
		return (0xC1BF68);
	else if (z <= 43)
		return (0xD6BF94);
	return (z <= 53 ? 0xEAD2C6 : 0xFFFFFF);
}

void	fdf_get_coordinates(t_env *e, int x, int y)
{
	if (e->m->iso)
	{
		e->m->x1 = (x - y) * e->zoom + e->m->tile_w;
		e->m->y1 = (x + y) * e->zoom / 2 + e->m->tile_h - e->m->map[y][x] *
			e->m->depth;
	}
	else
	{
		e->m->x1 = x * e->zoom + e->m->tile_w;
		e->m->y1 = y * e->zoom + e->m->tile_h - e->m->map[y][x] *
			e->m->depth;
	}
	if (e->m->dot)
	{
		e->m->x0 = e->m->x1;
		e->m->y0 = e->m->y1;
	}
}

void	fdf_bresenham(t_env *e)
{
	int	incrx;
	int	incry;
	int	err;
	int	cpyerr;

	e->m->dx = ft_abs(e->m->x1 - e->m->x0);
	e->m->dy = ft_abs(e->m->y1 - e->m->y0);
	incrx = e->m->x0 < e->m->x1 ? 1 : -1;
	incry = e->m->y0 < e->m->y1 ? 1 : -1;
	err = (e->m->dx > e->m->dy ? e->m->dx : -e->m->dy) / 2;
	while (e->m->x0 != e->m->x1 || e->m->y0 != e->m->y1)
	{
		e->img_str[e->p->x1 + (e->p->y1 * WIN_W)] = WHITE;
		cpyerr = err;
		if (cpyerr > -(e->m->dx))
		{
			err -= e->m->dy;
			e->m->x0 += incrx;
		}
		if (cpyerr < e->m->dy)
		{
			err += e->m->dx;
			e->m->y0 += incry;
		}
	}
}
