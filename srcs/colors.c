/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:23:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/22 16:03:56 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_rgb(int color, int i, int i_max)
{
	double	ratio;

	if (i > 0 && i < i_max / 2)
	{
		ratio = (double)(i_max / 2 - 1) / (double)i;
		if (color == RED)
			return ((int)ratio * 11 << 16);
		if (color == GREEN)
			return ((int)ratio * 11 << 8);
		if (color == BLUE)
			return ((int)ratio * 11);
	}
	else if (i >= i_max / 2 && i < i_max)
	{
		ratio = (double)(i_max / 2) / ((double)i - ((double)i_max / 2 - 1));
		if (color == RED)
			return ((0xFF << 16) + ((int)ratio * 11 << 8) + (int)ratio * 11);
		if (color == GREEN)
			return (((int)ratio * 11 << 16) + (0xFF << 8) + (int)ratio * 11);
		if (color == BLUE)
			return (((int)ratio * 11 << 16) + ((int)ratio * 11 << 8) + 0xFF);
	}
	return (BLACK);
}

static int	get_smooth_rgb(int color, int i, int i_max)
{
        int		r;
        int		g;
        int		b;
        double	ratio;
	
	ratio = (double)i / (double)i_max;
	r = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	g = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	b = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	if (color == DARK)
		return ((g << 16) + (r << 8) + g);
	else if (color == SMOOTHR)
		return ((b << 16) + (r << 8) + g);
	else if (color == SMOOTHG)
		return ((g << 16) + (b << 8) + r);
	return ((r << 16) + (g << 8) + b);
}

static int	get_psy_alt(int i, int i_max)
{
	if (i > 0 && i < i_max)
	{
		while (i > NBCOL)
			i /= NBCOL;
		if (i <= 1)
			return (0xFFA900);
		else if (i <= 2)
			return (0x00FF11);
		else if (i <= 3)
			return (0xA400FF);
		else if (i <= 4)
			return (0xF3FF00);
		else if (i <= 5)
			return (0xF400F4);
		else if (i <= 6)
			return (0xEF3E36);
		else if (i <= 7)
			return (0x00FFB2);
		else if (i <= 8)
			return (0xE29BFF);
		else if (i <= 9)
			return (0xF7B32B);
		return (0xE00070);
	}
	return (0X00747);
}

static int	get_psyche(int i, int i_max)
{
	if (i > 0 && i < i_max)
	{
		while (i > NBCOL)
			i /= NBCOL;
		if (i <= 1)
			return (0x1DAF22);
		else if (i <= 2)
			return (0x7AE7C7);
		else if (i <= 3)
			return (0xD81E5B);
		else if (i <= 4)
			return (0xF7B32B);
		else if (i <= 5)
			return (0xFF6B3A);
		else if (i <= 6)
			return (0x3B14FF);
		else if (i <= 7)
			return (0xFFEF42);
		else if (i <= 8)
			return (0xB143E0);
		else if (i <= 9)
			return (0x300000);
		return (0xC4ACBE);
	}
	return (0X00747);
}

int		get_color(int color, int i, int i_max)
{
	if (color == BLUE || color == RED || color == GREEN)
		return (get_rgb(color, i, i_max));
	else if (color == SMOOTHB || color == SMOOTHR || color == SMOOTHG || color == DARK)
		return (get_smooth_rgb(color, i, i_max));
	else if (color == BW && i == i_max)
		return (WHITE);
	else if (color == PSYCHE)
		return (get_psyche(i, i_max));
	else if (color == PSYALT)
		return (get_psy_alt(i, i_max));
	return (BLACK);
}
