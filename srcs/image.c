/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:14:07 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/15 14:15:30 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_pix(t_env *e, int x, int y)
{
	int	pix;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pix = (x * e->bpp / 8) + (y * e->s_l);
	e->img_str[pix++] = (e->img->color) & 0x000000FF;
	e->img_str[pix++] = (e->img->color >> 8) & 0x000000FF;
	e->img_str[pix] = (e->img->color >> 16) & 0x000000FF;
}

void	print_image(t_env *e)
{
	mlx_key_hook(e->win_ptr, deal_key, e);
	e->img_ptr = mlx_new_image(e->mlx_ptr, WIN_W, WIN_H);
	e->img_str = mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->s_l),
			&(e->endian));
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	mlx_loop(e->mlx_ptr);
}
