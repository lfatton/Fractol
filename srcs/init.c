/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:45 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/23 17:48:58 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_values(t_env *e)
{
	if (e->fract == JULIA)
	{
		e->p->k_r = -0.748;
		e->p->k_i = -0.086;
	}
	else if (e->fract == BJULIA)
	{
		e->p->k_r = -0.003;
		e->p->k_i = -1.263;
	}
	else if (e->fract == BRAIN)
	{
		e->p->k_r = 0.293;
		e->p->k_i = 0.298;
	}
	else if (e->fract == FROG)
	{
		e->p->k_r = -1.112;
		e->p->k_i = -0.413;
	}
	e->img->zoom = (e->cos ? 100 : 300);
	e->w = -HALF_W / e->img->zoom;
	e->h = -HALF_H / e->img->zoom;
	e->lock = 0;
}

void	reset(t_env *e)
{
	e->img->c = BW;
	e->img->i_max = 50;
	e->cos = 0;
	set_values(e);
}

void	error_fractol(char *err)
{
	ft_putendl(err);
	exit(EXIT_FAILURE);
}

int		quit_fractol(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img->ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	free(e->p);
	free(e->img);
	free(e);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_fractol(t_env *e, char *str)
{
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIN_W, WIN_H, str);
	mlx_do_key_autorepeaton(e->mlx_ptr);
	set_values(e);
	e->img->c = BW;
	e->img->i_max = 50;
	e->cos = 0;
	e->help = 0;
	create_image(e);
}
