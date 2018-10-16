/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:15:40 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 21:33:48 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e)
{
	int		row;
	int		col;
	int		i;
	double	tmp;

	row = 0;
	while (row < IMG_H)
	{
		col = 0;
		while (col < IMG_W)
		{
			e->p->c_re = (col - IMG_W / 2.0) * 4.0 / IMG_W;
			e->p->c_im = (row - IMG_H / 2.0) * 4.0 / IMG_W;
			e->p->x = 0;
			e->p->y = 0;
			i = 0;
			while ((e->p->x * e->p->x + e->p->y * e->p->y <= 4) && i < ITER_MAX)
			{
				tmp = e->p->x * e->p->x - e->p->y * e->p->y + e->p->c_re;
				e->p->y = 2 * e->p->x * e->p->y + e->p->c_im;
				e->p->x = tmp;
				i++;
			}
			if (i < ITER_MAX)
				create_pix(e, col, row, get_color(i));
			else
				create_pix(e, col, row, BLACK);
			col++;
		}
		row++;
	}
}
