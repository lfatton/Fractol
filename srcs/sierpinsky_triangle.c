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

void	sierpinsky_triangle(t_env *e)
{
	int	i;
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
			e->img_str[x + (y * WIN_W)] = WHITE;
			x++;
		}
		y++;
	}
}
