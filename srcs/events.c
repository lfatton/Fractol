/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:38:46 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/26 13:56:48 by lfatton          ###   ########.fr       */
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
		e->w = x / (e->img->zoom / R) + e->w - x / e->img->zoom;
		e->h = y / (e->img->zoom / R) + e->h - y / e->img->zoom;
	}
	else if (key == ZOOM_OUT)
	{
		e->w = x / (e->img->zoom * R) + e->w - x / e->img->zoom;
		e->h = y / (e->img->zoom * R) + e->h - y / e->img->zoom;
	}
}

void	toggle_k(t_env *e, int key, double x, double y)
{
	if (key != -1)
	{
		if (key == KEY_A)
			e->p->k_r -= 0.001;
		else if (key == KEY_D)
			e->p->k_r += 0.001;
		else if (key == KEY_W)
			e->p->k_i += 0.001;
		else
			e->p->k_i -= 0.001;
	}
	else
	{
		e->p->k_r += x / e->img->zoom;
		e->p->k_i += y / e->img->zoom;
	}
}

void	move_window(t_env *e, int key)
{
	if (key == UP_ARROW)
		e->h -= 0.1;
	else if (key == DOWN_ARROW)
		e->h += 0.1;
	else if (key == LEFT_ARROW)
		e->w -= 0.1;
	else
		e->w += 0.1;
}

void	change_color(t_env *e, int key)
{
	if (key == PAD_0)
		e->img->c = BW;
	else if (key == PAD_1)
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
	else if (key == PAD_7)
		e->img->c = PSYCHE;
	else if (key == PAD_8)
		e->img->c = PSYALT;
	else if (key == PAD_9)
		e->img->c = DARK;
}

void	change_fractal(t_env *e, int key)
{
	if (key == KEY_1 && (e->fract = MANDEL))
		e->fract_funct = &mandelbrot;
	else if (key == KEY_2 && (e->fract = JULIA))
		e->fract_funct = &julia;
	else if (key == KEY_3 && (e->fract = SHIP))
		e->fract_funct = &burning_ship;
	else if (key == KEY_4 && (e->fract = BJULIA))
		e->fract_funct = &burning_julia;
	else if (key == KEY_5 && (e->fract = TRI))
		e->fract_funct = &tricorn;
	else if (key == KEY_6 && (e->fract = BRAIN))
		e->fract_funct = &brain;
	else if (key == KEY_7 && (e->fract = BLOB))
		e->fract_funct = &mandelblob;
	else if (key == KEY_8 && (e->fract = FROG))
		e->fract_funct = &frog;
	if (key == KEY_C)
		e->cos = (e->cos == 0) ? 1 : 0;
	set_values(e);
}
