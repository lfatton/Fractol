/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:14:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 21:33:43 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int i)
{
	int	col;
	int ratio;
	int	r;
	int	g;
	int	b;

	if (i > 0 && i < ITER_MAX / 2 - 1)
	{
		ratio = (ITER_MAX / 2 - 1) / i;
		r = ratio * 10 << 16;
		g = 0 << 8;
		b = 0;
	}
	else
	{
		ratio = ITER_MAX - 1 / i;
		r = ratio * 10 << 16;
		g = 255 << 8;
		b = 255;
	}
	col = r + g + b;
	return (col);
}

void	create_pix(t_env *e, int x, int y, int col)
{
	int	pix;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pix = (x * e->bpp / 8) + (y * e->s_l);
	e->img_str[pix++] = (col) & 0x000000FF;
	e->img_str[pix++] = (col >> 8) & 0x000000FF;
	e->img_str[pix] = (col >> 16) & 0x000000FF;
}

void	print_image(t_env *e, int fract)
{
	mlx_key_hook(e->win_ptr, deal_key, e);
	e->img_ptr = mlx_new_image(e->mlx_ptr, WIN_W, WIN_H);
	e->img_str = mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->s_l),
			&(e->endian));
	if (fract == 1)
		mandelbrot(e);
	else if (fract == 2)
		julia(e);
	else if (fract == 3)
		burning_ship(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	mlx_loop(e->mlx_ptr);
}
