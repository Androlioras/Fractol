/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:49:24 by pribault          #+#    #+#             */
/*   Updated: 2017/01/16 19:15:28 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** includes
*/

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <pthread.h>

/*
** macros
*/

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

/*
** structures
*/

typedef unsigned char	t_c;

typedef struct	s_color
{
	t_c			r;
	t_c			g;
	t_c			b;
}				t_color;

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_point
{
	t_color		c;
	int			x;
	int			y;
}				t_point;

typedef struct	s_win
{
	void		*win;
	void		*mlx;
	void		*screen;
	char		*title;
	char		*l;
	int			size_l;
	int			h;
	int			w;
}				t_win;

typedef struct	s_menu
{
	void		*screen;
	char		*l;
	int			background;
	int			size_l;
	int			h;
	int			w;
}				t_menu;

typedef struct	s_main
{
	t_win		w;
	t_menu		m;
	t_complex	z;
	t_color		c;
	t_color		c2;
	long double	zoom;
	double		zoomw;
	double		zoomh;
	int			grab[6];
	int			threads;
	int			menu;
	int			pause;
	int			fract;
	int			i;
}				t_main;

typedef struct	s_band
{
	t_main		*win;
	int			i;
	int			j;
}				t_band;

/*
** protypes
*/

void			ft_log(char *str);
int				ft_error(char *str, int state);

t_main			*initialize(int argc, char **argv, int fract);

void			ft_draw(t_main *win);

void			print_fractal_mt(t_main *win);
void			print_fractal(t_band *band);
void			print_menu(t_main *win);

void			mandelbrot(t_main *win, t_complex c, t_point p);
void			julia(t_main *win, t_complex z, t_point p);
void			burning_ship(t_main *win, t_complex c, t_point p);

t_point			p(int x, int y);
t_color			ft_itoc(int n);
int				ft_ctoi(t_color c);
void			ft_pixel_put(t_point p, char *l, int size_l, int transp);
void			ft_pixel_put2(t_main *win, t_point p, int i);

int				ft_key_hook(int k, t_main *win);
int				ft_mouse(int x, int y, t_main *win);
int				ft_mouse_press(int k, int x, int y, t_main *win);
void			ft_mouse_press2(int x, int y, t_main *win);
int				ft_mouse_release(int k, int x, int y, t_main *win);
void			reset_grab(t_main *win);

#endif
