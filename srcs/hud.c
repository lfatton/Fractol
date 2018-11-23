/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:13:18 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/23 12:49:32 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_help(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 180, 0xFFFFFF, "Reset: R");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 160, 0xFFFFFF, "Mouse lock: SPACE");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 140, 0xFFFFFF, "Toggle julia/burning_julia/brain/frog param: W A S D or move mouse (unlocked)");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 120, 0xFFFFFF, "Zoom: PLUS MINUS (num pad) or mouse wheel");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 100, 0xFFFFFF, "Change iteration: LEFT CLICK (increase) RIGHT CLICK (decrease)");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 80, 0xFFFFFF, "Move view: ARROWS");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 60, 0xFFFFFF, "Change fractal: 1-8");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 40, 0xFFFFFF, "Change color: 0-9 (num pad)");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 20, 0xFFFFFF, "Sinusoidal form: C");
}

void	display_hud(t_env *e)
{
	int	start;

	start = 5;
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, start + 20, 0xFFFFFF, "Quit: esc");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, start + 40, 0xFFFFFF, "Show/hide help: H");
	if (e->help)
		display_help(e);
}
