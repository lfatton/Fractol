/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:45 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/21 22:38:56 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_env *e)
{
	if (key == KEY_SPACE)
		e->lock = (e->lock == 0) ? 1 : 0;
	if (key == ESC)
		quit_fractol(e);
	if (key == PAD_ADD || key == PAD_SUB)
		zoom(e, key, 0, 0);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
		toggle_k(e, key, 0, 0);
	if (key == UP_ARROW || key == DOWN_ARROW || key == LEFT_ARROW
		|| key == RIGHT_ARROW)
		move_window(e, key);
	if (key == PAD_1 || key == PAD_2 || key == PAD_3 || key == PAD_4
			|| key == PAD_5 || key == PAD_6)
		change_color(e, key);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4
		|| key == KEY_5 || key == KEY_6 || key == KEY_C)
		change_fractal(e, key);
	if (key == KEY_R)
		reset(e);
	return (0);
}

int		mouse_hook(int btn, int x, int y, t_env *e)
{
	if (btn == ZOOM_LOCK)
		e->lock = (e->lock == 0) ? 1 : 0;
	if (!e->lock)
	{
		if (btn == LEFT_BUTTON || btn == RIGHT_BUTTON)
			change_iter(e, btn);
		if (btn == ZOOM_IN || btn == ZOOM_OUT)
			zoom(e, btn, x, y);
	}
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	e->prev_mouse_x = e->mouse_x;
	e->prev_mouse_y = e->mouse_y;
	e->mouse_x = x;
	e->mouse_y = y;
	if (e->lock)
		toggle_k(e, -1, e->prev_mouse_x - e->mouse_x, e->prev_mouse_y - e->mouse_y);
	return (0);
}

void	set_values(t_env *e)
{
	e->img->zoom = 300;
	e->p->k_r = 0.353;
	e->p->k_i = 0.288;
	e->w = -HALF_W / e->img->zoom;
	e->h = -HALF_H / e->img->zoom;
	e->img->i_max = 25;
	e->lock = 0;
	e->cos = 0;
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
	e->img->c = SMOOTHB;
	e->img->pix = (int*)malloc(sizeof(int) * WIN_W * WIN_H);
	create_image(e);
	print_image(e);
}
