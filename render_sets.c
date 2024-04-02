/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:06:44 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 16:15:14 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_data *data)
{
	int	x;
	int	y;

	data->img.img = mlx_new_image(data->disp, WIDTH, HEIGHT);
	if (data->img.img == NULL)
		panic("Error calling mlx_new_image\n", data);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	if (ft_memcmp(data->name, "fern\0", 5) == 0)
	{
		fern(0, 0, data);
		mlx_put_image_to_window(data->disp, data->win, data->img.img, 0, 0);
		return (0);
	}
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			render_2(data, x, y);
	}
	mlx_put_image_to_window(data->disp, data->win, data->img.img, 0, 0);
	return (0);
}

int	render_2(t_data *data, int x, int y)
{
	int	index;

	if (ft_memcmp(data->name, "julia\0", 6) == 0)
	{
		julia((x * (data->vars.dist_x / WIDTH)) + data->vars.x_min,
			(y * (data->vars.dist_y / HEIGHT)) + data->vars.y_min, data);
	}
	else if (ft_memcmp(data->name, "mandelbrot\0", 11) == 0)
	{
		mandelbrot((x * (data->vars.dist_x / WIDTH)) + data->vars.x_min,
			(y * (data->vars.dist_y / HEIGHT)) + data->vars.y_min, data);
	}
	index = y * data->img.line_len + x * (data->img.bpp / 8);
	*((unsigned int *)(data->img.addr + index)) = data->collor;
	return (0);
}
