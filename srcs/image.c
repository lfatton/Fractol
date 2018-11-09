/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:14:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 19:13:06 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_rgb(t_env *e, int i)
{
	double	ratio;

	if (i > 0 && i < e->img->i_max / 2)
	{
		ratio = (double)(e->img->i_max / 2 - 1) / (double)i;
		if (e->img->c == RED)
			return ((int)ratio * 11 << 16);
		if (e->img->c == GREEN)
			return ((int)ratio * 11 << 8);
		if (e->img->c == BLUE)
			return ((int)ratio * 11);
	}
	else if (i >= e->img->i_max / 2 && i < e->img->i_max)
	{
		ratio = (double)(e->img->i_max / 2) / ((double)i
				- ((double)e->img->i_max / 2 - 1));
		if (e->img->c == RED)
			return ((0xFF << 16) + ((int)ratio * 11 << 8) + (int)ratio * 11);
		if (e->img->c == GREEN)
			return (((int)ratio * 11 << 16) + (0xFF << 8) + (int)ratio * 11);
		if (e->img->c == BLUE)
			return (((int)ratio * 11 << 16) + ((int)ratio * 11 << 8) + 0xFF);
	}
	return (BLACK);
}

int		get_smooth_rgb(t_env *e, int i)
{
	int		r;
	int		g;
	int		b;
	double	ratio;
	ratio = (double)i / (double)e->img->i_max;
	r = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	g = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	b = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	if (e->img->c == SMOOTHR)
		return ((b << 16) + (r << 8) + g);
	else if (e->img->c == SMOOTHG)
		return ((g << 16) + (b << 8) + r);
	return ((r << 16) + (g << 8) + b);
}

int		get_color(t_env *e, int i)
{
	int	*col;
	int j;

	j = -1;
	if (e->img->c == BLUE || e->img->c == RED || e->img->c == GREEN)
		return (get_rgb(e, i));
	else if (e->img->c == SMOOTHB || e->img->c == SMOOTHR || e->img->c == SMOOTHG)
		return (get_smooth_rgb(e, i));
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
	if (e->fract == MANDEL || e->fract == SHIP || e->fract == TRI)
	{
		e->p->z_r = 0;
		e->p->z_i = 0;
		e->p->c_r = (double)e->p->x / e->img->zoom + e->w;
		e->p->c_i = (double)e->p->y / e->img->zoom + e->h;
		if (e->cos)
		{
			e->p->c_r = cos(e->p->c_r);
			e->p->c_i = cos(e->p->c_i);
		}
	}
	else if (e->fract == JULIA || e->fract == BJULIA || e->fract == BRAIN)
	{
		e->p->z_r = (double)e->p->x / e->img->zoom + e->w;
		e->p->z_i = (double)e->p->y / e->img->zoom + e->h;
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
	e->fractal_function((void*)e);
}

void	*multithread(void *env)
{	t_env	*e;

	e = (t_env*)env;
	pthread_exit(NULL);
}

void	print_image(t_env *e)
{
	int	i;

	i = -1;
	e->p->y = -1;
	create_image(e);
	while (++i < THREADS)
		if (pthread_create(&e->thrds[i], NULL, multithread, e))
			error_fractol("cannot create thread");
	i = -1;
	while (++i > THREADS)
		if (pthread_join(e->thrds[i], NULL))
			error_fractol("cannot join threads");
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
}
