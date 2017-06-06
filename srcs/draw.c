/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:42:31 by pribault          #+#    #+#             */
/*   Updated: 2016/12/15 17:12:59 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_main *win, t_complex c, t_point p)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z = win->z;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < win->i)
	{
		tmp = z;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2 * tmp.r * tmp.i + c.i;
		i++;
	}
	ft_pixel_put2(win, p, i);
}

void	julia(t_main *win, t_complex z, t_point p)
{
	t_complex	c;
	t_complex	tmp;
	int			i;

	c = win->z;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < win->i)
	{
		tmp = z;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2 * tmp.r * tmp.i + c.i;
		i++;
	}
	ft_pixel_put2(win, p, i);
}

void	burning_ship(t_main *win, t_complex c, t_point p)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z = win->z;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < win->i)
	{
		tmp.r = (z.r >= 0) ? z.r : -z.r;
		tmp.i = (z.i >= 0) ? z.i : -z.i;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2 * tmp.r * tmp.i + c.i;
		i++;
	}
	ft_pixel_put2(win, p, i);
}

void	ft_draw(t_main *win)
{
	print_fractal_mt(win);
	mlx_hook(win->w.win, 2, (1L << 0), ft_key_hook, win);
	mlx_hook(win->w.win, 6, (1L << 6), ft_mouse, win);
	mlx_hook(win->w.win, 5, (1L << 3), ft_mouse_release, win);
	mlx_hook(win->w.win, 4, (1L << 2), ft_mouse_press, win);
	mlx_loop(win->w.mlx);
}
