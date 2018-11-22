/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:14:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/21 22:38:58 by lfatton          ###   ########.fr       */
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

int		get_psyche(int i, int i_max)
{
	if (i > 0 && i < i_max)
	{
		while (i > NBCOL)
			i /= NBCOL;
		if (i <= 1)
			return (0x1DAF22);
		else if (i <= 2)
			return (0x7AE7C7);
		else if (i <= 3)
			return (0xD81E5B);
		else if (i <= 4)
			return (0xF7B32B);
		else if (i <= 5)
			return (0xEF3E36);
		else if (i <= 6)
			return (0x3B14FF);
		else if (i <= 7)
			return (0xFFEF42);
		else if (i <= 8)
			return (0xB143E0);
		else if (i <= 9)
			return (0x300000);
		return (0xC4ACBE);
	}
	return (0X00747);
}

int		get_color(t_env *e, int i)
{
	if (e->img->c == BLUE || e->img->c == RED || e->img->c == GREEN)
		return (get_rgb(e, i));
	else if (e->img->c == SMOOTHB || e->img->c == SMOOTHR || e->img->c == SMOOTHG)
		return (get_smooth_rgb(e, i));
	else if (e->img->c == BW && i == e->img->i_max)
		return (WHITE);
	else if (e->img->c == PSYCHE)
			return (get_psyche(i, e->img->i_max));
	return (BLACK);
}

void	pow_coords(t_point *p)
{
	p->z_r2 = p->z_r * p->z_r;
	p->z_i2 = p->z_i * p->z_i;
}

void	get_coords(t_env *e, t_point *p, int x, int y)
{
	if (e->fract == MANDEL || e->fract == SHIP || e->fract == TRI)
	{
		p->z_r = 0;
		p->z_i = 0;
		p->c_r = x / e->img->zoom + e->w;
		p->c_i = y / e->img->zoom + e->h;
		if (e->cos)
		{
			p->c_r = cos(p->c_r);
			p->c_i = cos(p->c_i);
		}
	}
	else if (e->fract == JULIA || e->fract == BJULIA || e->fract == BRAIN)
	{
		p->z_r = x / e->img->zoom + e->w;
		p->z_i = y / e->img->zoom + e->h;
		if (e->cos)
		{
			p->z_r = cos(p->z_r);
			p->z_i = cos(p->z_i);
		}
	}
	p->z_r2 = p->z_r * p->z_r;
	p->z_i2 = p->z_i * p->z_i;
}

void	create_image(t_env *e)
{
	int	bpp;
	int	s_l;
	int	endian;

	e->img->ptr = mlx_new_image(e->mlx_ptr, WIN_W, WIN_H);
	e->img->str = (int*)mlx_get_data_addr(e->img->ptr, &bpp, &s_l, &endian);
}

void	*multithread(t_thrds *fract_thrds){
	int	x;
	int	y;

	y = WIN_H / THREADS * fract_thrds->i;
	while (y < WIN_H / THREADS * (fract_thrds->i + 1))
	{
		x = 0;
		while (x < WIN_W)
		{
			fract_thrds->e->fract_funct(fract_thrds->e, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}
void	print_image(t_env *e)
{
	pthread_t	thrds[THREADS];
	t_thrds		*fract_thrds;
	int	i;

	i = 0;
	while (i < THREADS)
	{
		fract_thrds = (t_thrds*)malloc(sizeof(t_thrds));
		fract_thrds->i = i;
		fract_thrds->e = (t_env*)malloc(sizeof(t_env));
		ft_memcpy(fract_thrds->e, e, sizeof(t_env));
		if (pthread_create(&thrds[i], NULL, (void*)multithread, fract_thrds))
			error_fractol("cannot create thread");
		i++;
	}
	while (i--)
		if (pthread_join(thrds[i], NULL))
			error_fractol("cannot join threads");
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img->ptr, 0, 0);
	free(fract_thrds->e);
	free(fract_thrds);
}
