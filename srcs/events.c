/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:38:46 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/21 18:58:53 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *e, int key)
{
	if (key == UP_ARROW)
		e->img->zoom -= 0.01;
	else
		e->img->zoom += 0.01;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	toggle_k(t_env *e, int key)
{
	if (key == KEY_A)
		e->p->k_r -= 0.01;
	else if (key == KEY_D)
		e->p->k_r += 0.01;
	else if (key == KEY_W)
		e->p->k_i += 0.01;
	else
		e->p->k_i -= 0.01;
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	reset(t_env *e)
{
	set_values(e);
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	print_image(e);
}

void	set_values(t_env *e)
{
	e->img->zoom = 4.0;
	e->p->k_r = 0.353;
	e->p->k_i = 0.288;
	e->p->y = -1;
}
