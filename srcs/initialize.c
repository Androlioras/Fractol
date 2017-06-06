/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:10:04 by pribault          #+#    #+#             */
/*   Updated: 2017/06/06 10:54:44 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_main		*ft_flags(t_main *win, int argc, char **argv)
{
	int		i;

	i = 2;
	while (i < argc)
	{
		if (i + 2 < argc && strcmp(argv[i], "-size") == 0)
		{
			win->w.w = ft_atoi(argv[i + 1]);
			win->w.h = ft_atoi(argv[i + 2]);
			i += 2;
		}
		else if (i + 1 < argc && strcmp(argv[i], "-title") == 0)
			win->w.title = argv[++i];
		else
			ft_error("flags are:\n-size <width> <height>\n-title <name>", -1);
		i++;
	}
	return (win);
}

void		set_var(t_main *win, int fract)
{
	win->w.title = "fract_ol";
	win->threads = 4;
	win->fract = fract;
	win->zoom = 300;
	win->zoomw = -1.5;
	win->zoomh = -1;
	win->pause = 0;
	win->w.h = 800;
	win->w.w = 800;
	win->menu = 0;
	win->i = 100;
	win->z.r = 0;
	win->z.i = 0.65;
	win->c2 = ft_itoc(0x000055);
	win->c = ft_itoc(0x00ffff);
	win->m.background = 0xFFFFFF;
	win->grab[0] = 0;
	win->grab[1] = 0;
	win->grab[2] = 0;
	win->grab[3] = 0;
	win->grab[4] = 0;
	win->grab[5] = 0;
}

t_main		*initialize(int argc, char **argv, int fract)
{
	t_main	*win;
	int		b;
	int		e;

	if (!(win = (t_main*)malloc(sizeof(t_main))))
		ft_error("can't allocate structure", -1);
	set_var(win, fract);
	win = ft_flags(win, argc, argv);
	win->m.h = win->w.h;
	win->m.w = win->w.w / 4;
	if (!(win->w.mlx = mlx_init()))
		ft_error("can't initialize mlx", -1);
	win->w.win = mlx_new_window(win->w.mlx, win->w.w, win->w.h, win->w.title);
	if (!win->w.win)
		ft_error("can't open window", -1);
	if (!(win->w.screen = mlx_new_image(win->w.mlx, win->w.w, win->w.h)))
		ft_error("can't create a new image", -1);
	win->w.l = mlx_get_data_addr(win->w.screen, &b, &(win->w.size_l), &e);
	if (!(win->m.screen = mlx_new_image(win->w.mlx, win->m.w, win->m.h)))
		ft_error("can't create a new image", -1);
	win->m.l = mlx_get_data_addr(win->m.screen, &b, &(win->m.size_l), &e);
	return (win);
}
