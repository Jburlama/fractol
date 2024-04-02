/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:08:10 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 16:44:49 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_funcs(t_data *data)
{
	data->disp = mlx_init();
	if (data->disp == NULL)
		panic("Error calling mlx_init\n", data);
	data->win = mlx_new_window(data->disp, WIDTH,
			HEIGHT, data->name);
	if (data->win == NULL)
		panic("Error calling mlx_new_window\n", data);
	mlx_mouse_hook(data->win, mouse_events, data);
	mlx_key_hook(data->win, key_release, data);
	mlx_hook(data->win,
		KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win,
		DestroyNotify, ButtonReleaseMask, quit, data);
	mlx_expose_hook(data->win, render, data);
	mlx_loop(data->disp);
}

void	invalid_args(void)
{
	write(2, "Invalid Argumets.\n", 18);
	write(2, "Usage:\n", 7);
	write(2, "./fractol mandelbrot\n", 21);
	write(2, "./fractol julia <real> <imag>\n", 31);
	write(2, "./fractol fern\n", 15);
	exit(1);
}

void	panic(char *str, t_data *data)
{
	perror(str);
	cleanup(data);
	exit(errno);
}

void	cleanup(t_data *data)
{
	if (data->disp)
	{
		if (data->img.img)
			mlx_destroy_image(data->disp, data->img.img);
		if (data->win)
			mlx_destroy_window(data->disp, data->win);
		mlx_destroy_display(data->disp);
		free(data->disp);
	}
}

int	quit(t_data *data)
{
	cleanup(data);
	exit(0);
}
