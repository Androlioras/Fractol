/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:08:09 by pribault          #+#    #+#             */
/*   Updated: 2017/01/16 19:15:02 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_press2(int x, int y, t_main *win)
{
	int			w[2];
	t_point		p;

	w[0] = win->m.w / 10;
	w[1] = win->m.w - win->m.w / 10;
	p.x = win->c2.r * (w[1] - w[0]) / 255 + w[0] + win->w.w - win->m.w;
	p.y = win->w.h / 11;
	win->grab[0] = (25 >= ft_power(p.x - x, 2) + ft_power(p.y - y, 2)) ? 1 : 0;
	p.x = win->c2.g * (w[1] - w[0]) / 255 + w[0] + win->w.w - win->m.w;
	p.y = 2 * win->w.h / 11;
	win->grab[1] = (25 >= ft_power(p.x - x, 2) + ft_power(p.y - y, 2)) ? 1 : 0;
	p.x = win->c2.b * (w[1] - w[0]) / 255 + w[0] + win->w.w - win->m.w;
	p.y = 3 * win->w.h / 11;
	win->grab[2] = (25 >= ft_power(p.x - x, 2) + ft_power(p.y - y, 2)) ? 1 : 0;
	p.x = win->c.r * (w[1] - w[0]) / 255 + w[0] + win->w.w - win->m.w;
	p.y = 6 * win->w.h / 11;
	win->grab[3] = (25 >= ft_power(p.x - x, 2) + ft_power(p.y - y, 2)) ? 1 : 0;
	p.x = win->c.g * (w[1] - w[0]) / 255 + w[0] + win->w.w - win->m.w;
	p.y = 7 * win->w.h / 11;
	win->grab[4] = (25 >= ft_power(p.x - x, 2) + ft_power(p.y - y, 2)) ? 1 : 0;
	p.x = win->c.b * (w[1] - w[0]) / 255 + w[0] + win->w.w - win->m.w;
	p.y = 8 * win->w.h / 11;
	win->grab[5] = (25 >= ft_power(p.x - x, 2) + ft_power(p.y - y, 2)) ? 1 : 0;
}

void	reset_grab(t_main *win)
{
	win->grab[0] = 0;
	win->grab[1] = 0;
	win->grab[2] = 0;
	win->grab[3] = 0;
	win->grab[4] = 0;
	win->grab[5] = 0;
}
