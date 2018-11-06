/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:38:46 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/25 19:13:12 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *e, int key, int x, int y)
{
	if (key == PAD_ADD || key == ZOOM_IN)
		e->img->zoom *= R;
	else if ((key == PAD_SUB || key == ZOOM_OUT) && e->img->zoom > 0)
		e->img->zoom /= R;
	if (key == ZOOM_IN)
	{
		e->w = (e->w + RATIO_W + (x - HALF_W) * (1 - 1 / R)) * R;
		e->h = (e->h + RATIO_W + (y - HALF_W) * (1 - 1 / R)) * R;
	}
	else if (key == ZOOM_OUT)
	{
		e->w = e->w / R - RATIO_W / R - (x - HALF_W) * R + (x - HALF_W);
		e->y = e->y / R - RATIO_W / R - (y - HALF_W) * R + (y - HALF_W);
	}
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	toggle_k(t_env *e, int key, double x, double y)
{
	if (key != -1)
	{
		if (key == KEY_A)
			e->p->k_r -= 0.005;
		else if (key == KEY_D)
			e->p->k_r += 0.005;
		else if (key == KEY_W)
			e->p->k_i += 0.005;
		else
			e->p->k_i -= 0.005;
	}
	else
	{
		e->p->k_r += x / e->img->zoom;
		e->p->k_i += y / e->img->zoom;
	}
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	move_window(t_env *e, int key)
{
	if (key == UP_ARROW)
		e->h -= 10;
	else if (key == DOWN_ARROW)
		e->h += 10;
	else if (key == LEFT_ARROW)
		e->w -= 10;
	else
		e->w += 10;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	change_iter(t_env *e, int btn)
{
	if (btn == LEFT_BUTTON)
		e->img->i_max += 1;
	else if (btn == RIGHT_BUTTON && e->img->i_max > 4)
		e->img->i_max -= 1;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	change_color(t_env *e, int key)
{
	if (key == PAD_1)
		e->img->c = BLUE;
	else if (key == PAD_2)
		e->img->c = RED;
	else if (key == PAD_3)
		e->img->c = GREEN;
	else if (key == PAD_4)
		e->img->c = SMOOTHB;
	else if (key == PAD_5)
		e->img->c = SMOOTHR;
	else if (key == PAD_6)
		e->img->c = SMOOTHG;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	change_fractal(t_env *e, int key)
{
	if (key == KEY_1)
		e->fract = MANDEL;
	else if (key == KEY_2)
		e->fract = JULIA;
	else if (key == KEY_3)
		e->fract = SHIP;
	else if (key == KEY_4)
		e->fract = BJULIA;
	else if (key == KEY_5)
		e->fract = TRI;
	set_values(e);
	if (key == KEY_C)
		e->cos = 1;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	reset(t_env *e)
{
	set_values(e);
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}
