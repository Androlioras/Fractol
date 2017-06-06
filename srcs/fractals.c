/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 00:32:34 by pribault          #+#    #+#             */
/*   Updated: 2016/12/14 00:32:35 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_mandelbrot(t_band *band)
{
	t_complex	x;
	t_point		p;
	int			j;
	int			h;
	int			w;

	p.y = 0;
	j = band->j;
	h = band->win->w.h;
	w = band->win->w.w;
	while (p.y < h)
	{
		p.x = band->i;
		x.i = (double)p.y / band->win->zoom + band->win->zoomw;
		while (p.x < j && p.x < w)
		{
			x.r = (double)p.x / band->win->zoom + band->win->zoomh;
			mandelbrot(band->win, x, p);
			p.x++;
		}
		p.y++;
	}
}

void	print_julia(t_band *band)
{
	t_complex	x;
	t_point		p;
	int			j;
	int			h;
	int			w;

	p.y = 0;
	j = band->j;
	h = band->win->w.h;
	w = band->win->w.w;
	while (p.y < h)
	{
		p.x = band->i;
		x.i = (double)p.y / band->win->zoom + band->win->zoomw;
		while (p.x < j && p.x < w)
		{
			x.r = (double)p.x / band->win->zoom + band->win->zoomh;
			julia(band->win, x, p);
			p.x++;
		}
		p.y++;
	}
}

void	print_burning_ship(t_band *band)
{
	t_complex	x;
	t_point		p;
	int			j;
	int			h;
	int			w;

	p.y = 0;
	j = band->j;
	h = band->win->w.h;
	w = band->win->w.w;
	while (p.y < h)
	{
		p.x = band->i;
		x.i = (double)p.y / band->win->zoom + band->win->zoomw;
		while (p.x < j && p.x < w)
		{
			x.r = (double)p.x / band->win->zoom + band->win->zoomh;
			burning_ship(band->win, x, p);
			p.x++;
		}
		p.y++;
	}
}

void	print_fractal(t_band *band)
{
	if (band->win->fract == MANDELBROT)
		print_mandelbrot(band);
	if (band->win->fract == JULIA)
		print_julia(band);
	if (band->win->fract == BURNING_SHIP)
		print_burning_ship(band);
}
