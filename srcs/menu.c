/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 05:04:55 by pribault          #+#    #+#             */
/*   Updated: 2017/01/16 19:06:43 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	p(int x, int y)
{
	t_point		a;

	a.x = x;
	a.y = y;
	return (a);
}

void	ft_sphere(t_main *win, t_point a, int r)
{
	t_point		i;

	i.y = a.y - r;
	i.c = ft_itoc(0xFFFFFF);
	while (i.y <= a.y + r)
	{
		i.x = a.x - r;
		while (i.x <= a.x + r)
		{
			if (r * r >= ft_power(i.x - a.x, 2) + ft_power(i.y - a.y, 2))
				ft_pixel_put(i, win->m.l, win->m.size_l, 0);
			i.x++;
		}
		i.y++;
	}
}

void	ft_line(t_main *win, t_point x, int y, int c)
{
	t_point	i;
	int		tmp;

	i.y = y;
	i.c = ft_itoc(0xFFFFFF);
	tmp = x.x;
	while (x.x <= x.y)
	{
		i.x = x.x;
		ft_pixel_put(i, win->m.l, win->m.size_l, 0);
		x.x++;
	}
	i.x = c * (x.y - tmp) / 255 + tmp;
	ft_sphere(win, i, 5);
}

void	ft_s(t_main *win, t_point a, t_point b, t_color c)
{
	t_point		border;
	t_point		i;

	i.y = a.y;
	i.c = c;
	while (i.y < b.y)
	{
		i.x = a.x;
		while (i.x < b.x)
		{
			if (i.x == a.x || i.x == b.x || i.y == a.y || i.y == b.y)
			{
				border = i;
				border.c = ft_itoc(0xFFFFFF);
				ft_pixel_put(border, win->m.l, win->m.size_l, 0);
			}
			else
				ft_pixel_put(i, win->m.l, win->m.size_l, 0);
			i.x++;
		}
		i.y++;
	}
}

void	print_menu(t_main *w)
{
	t_point	i;
	int		l;

	i.y = 0;
	i.c = ft_itoc(w->m.background);
	while (i.y < w->m.h)
	{
		i.x = 0;
		while (i.x < w->m.w)
		{
			ft_pixel_put(i, w->m.l, w->m.size_l, 96);
			i.x++;
		}
		i.y++;
	}
	l = w->m.w;
	ft_line(w, p(l / 10, l * 0.9), w->w.h / 11, w->c2.r);
	ft_line(w, p(l / 10, l * 0.9), 2 * w->w.h / 11, w->c2.g);
	ft_line(w, p(l / 10, l * 0.9), 3 * w->w.h / 11, w->c2.b);
	ft_line(w, p(l / 10, l * 0.9), 6 * w->w.h / 11, w->c.r);
	ft_line(w, p(l / 10, l * 0.9), 7 * w->w.h / 11, w->c.g);
	ft_line(w, p(l / 10, l * 0.9), 8 * w->w.h / 11, w->c.b);
	ft_s(w, p(l / 5, 4 * w->w.h / 11), p(l - l / 5, 5 * w->w.h / 11), w->c2);
	ft_s(w, p(l / 5, 9 * w->w.h / 11), p(l - l / 5, 10 * w->w.h / 11), w->c);
	mlx_put_image_to_window(w->w.mlx, w->w.win, w->m.screen, w->w.w - l, 0);
}
