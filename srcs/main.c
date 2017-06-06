/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:52:39 by pribault          #+#    #+#             */
/*   Updated: 2017/01/16 19:37:30 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_error(char *str, int state)
{
	ft_log(ft_strjoin("[error] ", str));
	if (state == -1)
	{
		ft_log("exiting");
		exit(0);
	}
	return (0);
}

void	clear_log(void)
{
	int		fd;

	fd = open("log", O_TRUNC);
	if (fd)
		close(fd);
	fd = open("log", O_CREAT, 0666);
	if (fd)
		close(fd);
}

void	ft_log(char *str)
{
	int		fd;

	fd = open("log", O_APPEND | O_WRONLY);
	if (fd < 0)
		return ;
	ft_putstr_fd("[log] ", fd);
	ft_putendl_fd(str, fd);
	close(fd);
}

void	ft_usage(void)
{
	ft_log("usage is: ./fractol <fractal> <flags>");
	ft_log("fractals available:\n-Mandelbrot\n-Julia\n-Burning_ship");
	ft_log("flags available:\n-title <title>\n-size <width> <height>");
}

int		main(int argc, char **argv)
{
	t_main	*win;

	clear_log();
	if (argc >= 2)
	{
		win = NULL;
		if (strcmp(argv[1], "Mandelbrot") == 0)
			win = initialize(argc, argv, MANDELBROT);
		else if (strcmp(argv[1], "Julia") == 0)
			win = initialize(argc, argv, JULIA);
		else if (strcmp(argv[1], "Burning_ship") == 0)
			win = initialize(argc, argv, BURNING_SHIP);
		else
			ft_error("fractal unknown", -1);
		ft_draw(win);
		free(win->w.mlx);
		free(win->w.win);
		free(win);
	}
	else
	{
		ft_error("wrong number of arguments.", 0);
		ft_usage();
	}
	return (0);
}
