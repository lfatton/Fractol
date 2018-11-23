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

void	get_coords(t_env *e, t_point *p, int x, int y)
{
	if (e->fract == MANDEL || e->fract == SHIP || e->fract == TRI || e->fract == BLOB)
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
	else if (e->fract == JULIA || e->fract == BJULIA || e->fract == BRAIN || e->fract == FROG)
	{
		p->z_r = x / e->img->zoom + e->w;
		p->z_i = y / e->img->zoom + e->h;
		if (e->cos)
		{
			p->z_r = cos(p->z_r);
			p->z_i = cos(p->z_i);
		}
	}
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
	free(fract_thrds->e);
	free(fract_thrds);
}
