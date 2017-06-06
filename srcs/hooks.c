/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:42:37 by pribault          #+#    #+#             */
/*   Updated: 2017/01/16 19:20:09 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_hook(int k, t_main *w)
{
	if (k == 53)
		exit(0);
	if (k == 76)
		w->menu = (w->menu == 0) ? 1 : 0;
	if (k == 49 || k == 76)
		w->pause = (w->pause == 0) ? 1 : 0;
	w->pause = (w->menu == 1 && w->pause == 0) ? 1 : w->pause;
	if (k == 69 || k == 78)
		w->i += (k == 69) ? 2 : -2;
	w->i = (w->i <= 0) ? 1 : w->i;
	if (k == 126 || k == 125)
		w->zoomw += (k == 126) ? -20 / w->zoom : 20 / w->zoom;
	if (k == 123 || k == 124)
		w->zoomh += (k == 123) ? -20 / w->zoom : 20 / w->zoom;
	print_fractal_mt(w);
	return (1);
}

int		ft_mouse(int x, int y, t_main *w)
{
	if (w->pause == 1 || x >= w->w.w || x < 0 || y >= w->w.h || y < 0)
		return (0);
	w->z.r = (double)x / (double)w->w.w;
	w->z.i = (double)y / (double)w->w.h;
	print_fractal_mt(w);
	return (1);
}

void	calc_zoom(int k, int x, int y, t_main *w)
{
	long double	a;
	long double	b;

	a = ((double)w->w.w / w->zoom) / (w->w.w * 3);
	b = ((double)w->w.h / w->zoom) / (w->w.h * 3);
	if (k == 4)
	{
		w->zoomh += (a * (double)x);
		w->zoomw += (b * (double)y);
	}
	else
	{
		w->zoomh -= (a * 1.5 * (double)x);
		w->zoomw -= (b * 1.5 * (double)y);
	}
	w->zoom *= (k == 4) ? 1.5 : 1 / 1.5;
}

int		ft_mouse_press(int k, int x, int y, t_main *w)
{
	if (k == 4 || k == 5)
		calc_zoom(k, x, y, w);
	print_fractal_mt(w);
	if (w->menu == 0)
		return (1);
	ft_mouse_press2(x, y, w);
	return (1);
}

int		ft_mouse_release(int k, int x, int y, t_main *w)
{
	int		l[2];

	l[0] = w->m.w / 10;
	l[1] = w->m.w - w->m.w / 10;
	if (k != 1)
		return (1);
	if (w->grab[0] == 1 && w->w.w - w->m.w + l[0] < x && x < w->w.w - l[0])
		w->c2.r = (x - (w->w.w - w->m.w + l[0])) * 255 / (l[1] - l[0]);
	if (w->grab[1] == 1 && w->w.w - w->m.w + l[0] < x && x < w->w.w - l[0])
		w->c2.g = (x - (w->w.w - w->m.w + l[0])) * 255 / (l[1] - l[0]);
	if (w->grab[2] == 1 && w->w.w - w->m.w + l[0] < x && x < w->w.w - l[0])
		w->c2.b = (x - (w->w.w - w->m.w + l[0])) * 255 / (l[1] - l[0]);
	if (w->grab[3] == 1 && w->w.w - w->m.w + l[0] < x && x < w->w.w - l[0])
		w->c.r = (x - (w->w.w - w->m.w + l[0])) * 255 / (l[1] - l[0]);
	if (w->grab[4] == 1 && w->w.w - w->m.w + l[0] < x && x < w->w.w - l[0])
		w->c.g = (x - (w->w.w - w->m.w + l[0])) * 255 / (l[1] - l[0]);
	if (w->grab[5] == 1 && w->w.w - w->m.w + l[0] < x && x < w->w.w - l[0])
		w->c.b = (x - (w->w.w - w->m.w + l[0])) * 255 / (l[1] - l[0]);
	reset_grab(w);
	print_fractal_mt(w);
	x++;
	y++;
	return (1);
}
