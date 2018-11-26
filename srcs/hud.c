/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:13:18 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/26 16:50:40 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	display_help(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 225, 0xFFFFFF, "Reset: "
			"R");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 200, 0xFFFFFF, "Mouse "
			"lock: zoom button or SPACE");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 175, 0xFFFFFF, "Toggle "
			"julia/burning_julia/brain/frog param: W A S D or move mouse "
			"(unlocked)");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 150, 0xFFFFFF, "Zoom: "
			"PLUS MINUS (num pad) or mouse wheel");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 125, 0xFFFFFF, "Change "
			"iteration: LEFT CLICK (increase) RIGHT CLICK (decrease)");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 100, 0xFFFFFF, "Move "
			"view: ARROWS");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 75, 0xFFFFFF, "Change "
			"fractal: 1-8");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 50, 0xFFFFFF, "Change "
			"color: 0-9 (num pad)");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, WIN_H - 25, 0xFFFFFF, "Sinus"
			"oidal form: C");
}

void		display_hud(t_env *e)
{
	int	start;

	start = 5;
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, start + 25, 0xFFFFFF, "Quit: "
			"esc");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 10, start + 50, 0xFFFFFF, "Show/hide"
			" help: H");
	if (e->help)
		display_help(e);
}
