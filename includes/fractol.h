/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:08:44 by lfatton           #+#    #+#             */
/*   Updated: 2018/10/21 19:51:22 by lfatton          ###   ########.fr       */
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

# include <stdio.h>

# define WIN_W 1920
# define WIN_H 1080
# define HALF_W WIN_W / 2
# define HALF_H WIN_H / 2
# define R 1.05
# define RATIO_W (WIN_W - WIN_W / R) / 2

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define RED 1
# define GREEN 2
# define BLUE 3

# define MANDEL 1
# define JULIA 2
# define SHIP 3
# define TRI 4

# if __APPLE__
#  define ESC 53
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 23
#  define UP_ARROW 126
#  define DOWN_ARROW 125
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
#  define PAD_ADD 69
#  define PAD_SUB 78
#  define PAD_1 83
#  define PAD_2 84
#  define PAD_3 85
#  define PAD_4 86
#  define PAD_5 87
#  define PAD_6 88
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_R 15
#  define KEY_F 3
#  define KEY_DOT 47
#  define KEY_SPACE 49
# else
#  define ESC 65307
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define PAD_ADD 65451
#  define PAD_SUB 65453
#  define PAD_1 65436
#  define PAD_2 65433
#  define PAD_3 65435
#  define PAD_4 65430
#  define PAD_5 65437
#  define PAD_6 65432
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_R 114
#  define KEY_F 102
#  define KEY_DOT 46
#  define KEY_SPACE 32
# endif

# define LEFT_BUTTON 1
# define RIGHT_BUTTON 3
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ZOOM_LOCK 2

typedef struct	s_img
{
	int			c;
	double		zoom;
	int			i_max;
}				t_img;

typedef struct	s_point
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		k_r;
	double		k_i;
	int			x;
	int			y;
}				t_point;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int		*img_str;
	int			fract;
	double			w;
	double			h;
	int			x;
	int			y;
	int			lock;
	t_img		*img;
	t_point		*p;
}				t_env;

int				get_fractal_name(t_env *e, char *str);

int				key_hook(int key, t_env *e);
int				mouse_hook(int btn, int x, int y, t_env *e);
void			set_values(t_env *e);
void			error_fractol(char *err);
void			quit_fractol(t_env *e);
void			init_fractol(t_env *e, char *str);

void			mandelbrot(t_env *e);
void			julia(t_env *e);
void			burning_ship(t_env *e);
void			sierpinsky_triangle(t_env *e);

int				get_color(t_env *e, int i);
int				get_RGB(t_env *e, int i);
void			create_pix(t_env *e, int col);
void			print_image(t_env *e);

void			zoom(t_env *e, int key, int x, int y);
void			toggle_k(t_env *e, int key);
void			move_window(t_env *e, int key);
void			change_iter(t_env *e, int btn);
void			change_color(t_env *e, int key);
void			change_fractal(t_env *e, int key);
void			reset(t_env *e);

#endif
