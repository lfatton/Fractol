/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:00:59 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/23 18:56:58 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	sierpinsky_triangle(t_env *e)
{
	int		i;
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = -1;
			while (++i < e->img->i_max)
			{
				x += 2;
				y += 2;
			}
			e->p->x = x;
			e->p->y = y;
			create_pix(e, WHITE);
			x++;
		}
		y++;
	}

}
