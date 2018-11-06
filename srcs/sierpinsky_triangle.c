/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:00:59 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 17:50:55 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bresenham(t_env *e, int x0, int y0, int x1, int y1)
{
	int	incrx;
	int	incry;
	int	err;
	int	cpyerr;
	int	dx;
	int	dy;

	dx = ft_abs(x1 - x0);
	dy = ft_abs(y1 - y0);
	incrx = x0 < x1 ? 1 : -1;
	incry = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (x0 != x1 || y0 != y1)
	{
		e->img_str[x0 + (y0 * WIN_W)] = WHITE;
		cpyerr = err;
		if (cpyerr > -(dx))
		{
			err -= dy;
			x0 += incrx;
		}
		if (cpyerr < dy)
		{
			err += dx;
			y0 += incry;
		}
	}
}

void	sierpinsky_triangle(t_env *e)
{
	int	i;
	int	x;
	int	y;
	int 	x1;
	int	y1;
	int	x2;
	int	y2;

	x = WIN_W / 2;
	y = 0;
	x1 = WIN_W - 1;
	y1 = WIN_H - 1;
	x2 = 0;
	y2 = WIN_H - 1;
	bresenham(e, x, y, x1, y1);
	bresenham(e, x1, y1, x2, y2);
	bresenham(e, x2, y2, x, y);
	y = 0;
/*	while (y < WIN_H)
	{i*/
		x = 0;
	/*	while (x < WIN_W)
		{*/
			i = -1;
		/*	e->img_str[e->p->x + (e->p->y * WIN_W)] = WHITE;
			x++;
		}
		y++;
	}*/
}
