/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:08:44 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/16 19:47:34 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# define WIN_W 2560
# define WIN_H 1440

# define IMG_W 2560
# define IMG_H 1440
# define ITER_MAX 50

# define WHITE 0xFFFFFF
# define BLACK 0x000000

# if __APPLE__
#  define ESC 53
#  define UP_ARROW 126
#  define DOWN_ARROW 125
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_R 15
#  define KEY_F 3
#  define KEY_DOT 47
# else
#  define ESC 65307
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_R 114
#  define KEY_F 102
#  define KEY_DOT 46
# endif

typedef struct	s_img
{
	int		color;
}				t_img;

typedef struct	s_point
{
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		color[INT_MAX];
}				t_point;

typedef struct  s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;
	int		zoom;
	t_img	*img;
	t_point	*p;
}				t_env;

# include <stdio.h>
void	create_pix(t_env *e, int x, int y, int col);
void	init_fractol(t_env *e, char *strn, int fract);
int		deal_key(int key, t_env *e);
void	error_fractol(char *err);
void	quit_fractol(t_env *e);
void	mandelbrot(t_env *e);
void	julia(t_env *e);
void	burning_ship(t_env *e);
void	print_image(t_env *e, int fract);

#endif
