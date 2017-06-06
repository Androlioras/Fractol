/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:11:57 by pribault          #+#    #+#             */
/*   Updated: 2016/12/15 15:43:30 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	ft_itoc(int n)
{
	t_color	c;

	c.r = n / 0x10000;
	c.g = (n % 0x10000) / 0x100;
	c.b = n % 0x100;
	return (c);
}

int		ft_ctoi(t_color c)
{
	return (c.r * 0x10000 + c.g * 0x100 + c.b);
}

void	ft_pixel_put(t_point p, char *l, int size_l, int transp)
{
	l[p.y * size_l + p.x * 4 + 3] = transp;
	l[p.y * size_l + p.x * 4 + 2] = p.c.r;
	l[p.y * size_l + p.x * 4 + 1] = p.c.g;
	l[p.y * size_l + p.x * 4] = p.c.b;
}

int		ft_root(int n)
{
	int		i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

void	ft_pixel_put2(t_main *win, t_point p, int i)
{
	t_color		c;
	t_color		c2;
	int			s;

	c = win->c;
	c2 = win->c2;
	s = win->w.size_l;
	win->w.l[p.y * s + p.x * 4 + 2] = i * (c.r - c2.r) / win->i + c2.r;
	win->w.l[p.y * s + p.x * 4 + 1] = i * (c.g - c2.g) / win->i + c2.g;
	win->w.l[p.y * s + p.x * 4] = i * (c.b - c2.b) / win->i + c2.b;
}
