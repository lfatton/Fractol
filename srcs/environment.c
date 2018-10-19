/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:45 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 19:47:44 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_fractol(char *err)
{
	ft_putendl(err);
	exit(EXIT_FAILURE);
}

void	zoom(t_env *e, int key)
{
	if (key == UP_ARROW)
		e->img->zoom -= 0.01;
	else
		e->img->zoom += 0.01;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	toggle_k(t_env *e, int key)
{
	if (key == LEFT_ARROW)
	{	
		e->p->k_r -= 0.01;
		e->p->k_i -= 0.01;
	}
	else
	{	
		e->p->k_r += 0.01;
		e->p->k_i += 0.01;
	}
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	reset(t_env *e)
{
	set_values(e);
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

int		deal_key(int key, t_env *e)
{
	if (key == ESC)
		quit_fractol(e);
	if (key == UP_ARROW || key == DOWN_ARROW)
		zoom(e, key);
	if (key == LEFT_ARROW || key == RIGHT_ARROW)
		toggle_k(e, key);
	if (key == KEY_R)
		reset(e);
	return (0);
}

void	set_values(t_env *e)
{
	e->img->zoom = 4.0;
	e->p->k_r = 0.353;
	e->p->k_i = 0.288;
}

void	init_fractol(t_env *e, char *str)
{
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIN_W, WIN_H, str);
	set_values(e);
	print_image(e);
}

void	quit_fractol(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(EXIT_SUCCESS);
}
