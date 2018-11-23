/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfatton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:08:44 by lfatton           #+#    #+#             */
/*   Updated: 2018/11/22 22:48:21 by lfatton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"

# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# include <stdio.h>

# define THREADS 8
# define WIN_W 1920
# define WIN_H 1080
# define HALF_W WIN_W / 2.0
# define HALF_H WIN_H / 2.0
# define R 1.05

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define BW 0
# define BLUE 1
# define RED 2
# define GREEN 3
# define SMOOTHB 4
# define SMOOTHR 5
# define SMOOTHG 6
# define PSYCHE 7
# define PSYALT 8
# define DARK 9
# define NBCOL 10

# define MANDEL 1
# define JULIA 2
# define SHIP 3
# define BJULIA 4
# define TRI 5
# define BRAIN 6
# define BLOB 7
# define FROG 8

# define LEFT_BUTTON 1
# define RIGHT_BUTTON 3
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ZOOM_LOCK 2

# if __APPLE__
#  define ESC 53
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 23
#  define KEY_6 22
#  define KEY_7 26
#  define KEY_8 28
#  define UP_ARROW 126
#  define DOWN_ARROW 125
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
#  define PAD_ADD 69
#  define PAD_SUB 78
#  define PAD_0 82
#  define PAD_1 83
#  define PAD_2 84
#  define PAD_3 85
#  define PAD_4 86
#  define PAD_5 87
#  define PAD_6 88
#  define PAD_7 89
#  define PAD_8 91
#  define PAD_9 92
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_R 15
#  define KEY_C 8
#  define KEY_H 4
#  define KEY_SPACE 49
# else
#  define ESC 65307
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
#  define KEY_8 56
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define PAD_ADD 65451
#  define PAD_SUB 65453
#  define PAD_0 65438
#  define PAD_1 65436
#  define PAD_2 65433
#  define PAD_3 65435
#  define PAD_4 65430
#  define PAD_5 65437
#  define PAD_6 65432
#  define PAD_7 65429
#  define PAD_8 65431
#  define PAD_9 65434
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_R 114
#  define KEY_C 99
#  define KEY_H 104
#  define KEY_SPACE 32
# endif

typedef struct	s_img
{
	void		*ptr;
	int			*str;
	int			c;
	double		zoom;
	int			i_max;
}				t_img;

typedef struct	s_point
{
	double		c_r;
	double		c_i;
	double		prev_z_r;
	double		prev_z_i;
	double		z_r;
	double		z_i;
	double		k_r;
	double		k_i;
}				t_point;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fract;
	double		w;
	double		h;
	int			x;
	int			y;
	double		prev_mouse_x;
	double		prev_mouse_y;
	double		mouse_x;
	double		mouse_y;
	int			lock;
	int			cos;
	int			help;
	int			thrds_x;
	int			thrds_y;
	void		(*fract_funct)(struct s_env *e, int x, int y);
	t_img		*img;
	t_point		*p;
}				t_env;

typedef struct	s_thrds
{
	t_env		*e;
	int			i;
}				t_thrds;

int				get_fractal_name(t_env *e, char *str);

void			display_hud(t_env *e);

int				expose_hook(t_env *e);
int				key_hook(int key, t_env *e);
int				mouse_hook(int btn, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);
void			set_values(t_env *e);
void			error_fractol(char *err);
int				quit_fractol(t_env *e);
void			init_fractol(t_env *e, char *str);

void			mandelbrot(t_env *e, int x, int y);
void			julia(t_env *e, int x, int y);
void			burning_ship(t_env *e, int x, int y);
void			burning_julia(t_env *e, int x, int y);
void			tricorn(t_env *e, int x, int y);
void			brain(t_env *e, int x, int y);
void			mandelblob(t_env *e, int x, int y);
void			frog(t_env *e, int x, int y);

int				get_color(int color, int i, int i_max);

void			get_coords(t_env *e, t_point *p, int x, int y);
void			*multithread(t_thrds *fract_thrds);
void			create_image(t_env *e);
void			print_image(t_env *e);

void			zoom(t_env *e, int key, int x, int y);
void			toggle_k(t_env *e, int key, double x, double y);
void			move_window(t_env *e, int key);
void			change_iter(t_env *e, int btn);
void			change_color(t_env *e, int key);
void			change_fractal(t_env *e, int key);
void			reset(t_env *e);

#endif
