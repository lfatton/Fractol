/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:45 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/15 14:13:35 by lfatton          ###   ########.fr       */
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
	return (0);
}

void	init_fractol(t_env *e, char *str)
{
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIN_W, WIN_H, str);
	print_image(e);
}

void	quit_fractol(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(EXIT_SUCCESS);
}
