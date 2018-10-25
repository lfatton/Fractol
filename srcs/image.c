/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:14:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 17:50:52 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_rgb(t_env *e, int i)
{
	int	ratio;

	if (i > 0 && i < e->img->i_max / 2)
	{
		ratio = (e->img->i_max / 2 - 1) / i;
		if (e->img->c == RED)
			return (ratio * 11 << 16);
		if (e->img->c == GREEN)
			return (ratio * 11 << 8);
		if (e->img->c == BLUE)
			return (ratio * 11);
	}
	else if (i >= e->img->i_max / 2 && i < e->img->i_max)
	{
		ratio = (e->img->i_max / 2) / (i - (e->img->i_max / 2 - 1));
		if (e->img->c == RED)
			return ((0xFF << 16) + (ratio * 11 << 8) + ratio * 11);
		if (e->img->c == GREEN)
			return ((ratio * 11 << 16) + (0xFF << 8) + ratio * 11);
		if (e->img->c == BLUE)
			return ((ratio * 11 << 16) + (ratio * 11 << 8) + 0xFF);
	}
	return (BLACK);
}

int		get_color(t_env *e, int i)
{
	int	*col;
	int j;

	j = -1;
	if (e->img->c == RED || e->img->c == GREEN || e->img->c == BLUE)
		return (get_rgb(e, i));
	col = (int*)malloc(sizeof(int) * e->img->i_max);
	while (++j < e->img->i_max)
	{
		col[j] = i;
	}
	return (col[i]);
}

void	pow_coords(t_env *e)
{
	e->p->z_r2 = e->p->z_r * e->p->z_r;
	e->p->z_i2 = e->p->z_i * e->p->z_i;
}

void	get_coords(t_env *e)
{
	if (e->fract == MANDEL || e->fract == SHIP)
	{
		e->p->z_r = 0;
		e->p->z_i = 0;
		e->p->c_r = (e->p->x + e->w) / e->img->zoom;
		e->p->c_i = (e->p->y + e->h) / e->img->zoom;
		if (e->cos)
		{
			e->p->c_r = cos(e->p->c_r);
			e->p->c_i = cos(e->p->c_i);
		}
	}
	else if (e->fract == JULIA || e->fract == BJULIA)
	{
		e->p->z_r = (e->p->x + e->w) / e->img->zoom;
		e->p->z_i = (e->p->y + e->h) / e->img->zoom;
		if (e->cos)
		{
			e->p->z_r = cos(e->p->z_r);
			e->p->z_i = cos(e->p->z_i);
		}
	}
	e->p->z_r2 = e->p->z_r * e->p->z_r;
	e->p->z_i2 = e->p->z_i * e->p->z_i;
}

void	create_image(t_env *e)
{
	int	bpp;
	int	s_l;
	int	endian;

	e->img_ptr = mlx_new_image(e->mlx_ptr, WIN_W, WIN_H);
	e->img_str = (int*)mlx_get_data_addr(e->img_ptr, &bpp, &s_l, &endian);
}

void	print_image(t_env *e)
{
	e->p->y = -1;
	mlx_key_hook(e->win_ptr, key_hook, e);
	mlx_mouse_hook(e->win_ptr, mouse_hook, e);
	create_image(e);
	if (e->fract == MANDEL)
		mandelbrot(e);
	else if (e->fract == JULIA)
		julia(e);
	else if (e->fract == SHIP)
		burning_ship(e);
	else if (e->fract == BJULIA)
		burning_julia(e);
	else if (e->fract == TRI)
		sierpinsky_triangle(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	mlx_loop(e->mlx_ptr);
}
