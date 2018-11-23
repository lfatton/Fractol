/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:43:57 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/23 17:54:06 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_env *e)
{
	if (key == ESC)
		quit_fractol(e);
	if (key == PAD_ADD || key == PAD_SUB)
		zoom(e, key, 0, 0);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
		toggle_k(e, key, 0, 0);
	if (key == UP_ARROW || key == DOWN_ARROW || key == LEFT_ARROW
			|| key == RIGHT_ARROW)
		move_window(e, key);
	if (key == PAD_0 || key == PAD_1 || key == PAD_2 || key == PAD_3 ||
			key == PAD_4 || key == PAD_5 || key == PAD_6 || key == PAD_7
			|| key == PAD_8 || key == PAD_9)
		change_color(e, key);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4
			|| key == KEY_5 || key == KEY_6 || key == KEY_7 || key == KEY_8
			|| key == KEY_C)
		change_fractal(e, key);
	if (key == KEY_H)
		e->help = (e->help == 0) ? 1 : 0;
	if (key == KEY_R)
		reset(e);
	expose_hook(e);
	if (key == KEY_SPACE)
		e->lock = (e->lock == 0) ? 1 : 0;
	return (0);
}

int	mouse_hook(int btn, int x, int y, t_env *e)
{
	if (btn == ZOOM_LOCK)
		e->lock = (e->lock == 0) ? 1 : 0;
	if (!e->lock)
	{
		if (btn == LEFT_BUTTON)
			e->img->i_max += 1;
		else if (btn == RIGHT_BUTTON && e->img->i_max > 4)
			e->img->i_max -= 1;
		if (btn == ZOOM_IN || btn == ZOOM_OUT)
			zoom(e, btn, x, y);
	}
	expose_hook(e);
	return (0);
}

int	mouse_motion(int x, int y, t_env *e)
{
	e->prev_mouse_x = e->mouse_x;
	e->prev_mouse_y = e->mouse_y;
	e->mouse_x = x;
	e->mouse_y = y;
	if (e->lock)
		toggle_k(e, -1, e->prev_mouse_x - e->mouse_x, e->prev_mouse_y -
				e->mouse_y);
	expose_hook(e);
	return (0);
}

int	expose_hook(t_env *e)
{
	print_image(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img->ptr, 0, 0);
	display_hud(e);
	return (0);
}
