/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:45 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/21 19:51:24 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_fractol(char *err)
{
	ft_putendl(err);
	exit(EXIT_FAILURE);
}

int		deal_key(int key, t_env *e)
{
	if (key == ESC)
		quit_fractol(e);
	if (key == UP_ARROW || key == DOWN_ARROW)
		zoom(e, key);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
		toggle_k(e, key);
	if (key == KEY_R)
		reset(e);
	return (0);
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
