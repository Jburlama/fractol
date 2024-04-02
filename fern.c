/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:21:52 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 16:24:41 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fern(t_data *data, char *name)
{
	data->vars.x_min = -6;
	data->vars.x_max = 6;
	data->vars.y_min = 30.0;
	data->vars.y_max = 10.0;
	if (data->vars.x_min >= 0)
		data->vars.dist_x = data->vars.x_max - data->vars.x_min;
	else if (data->vars.x_max <= 0)
		data->vars.dist_x = data->vars.x_min - data->vars.x_max;
	else
		data->vars.dist_x = -data->vars.x_min + data->vars.x_max;
	if (data->vars.y_min >= 0)
		data->vars.dist_y = data->vars.y_max - data->vars.y_min;
	else if (data->vars.y_max <= 0)
		data->vars.dist_y = data->vars.y_min - data->vars.y_max;
	else
		data->vars.dist_y = -data->vars.y_min + data->vars.y_max;
	data->name = name;
	data->iter = 10000;
	data->collor_depth = GREEN;
}

void	fern(double x, double y, t_data *data)
{
	int	i;
	int	rand_num;

	i = -1;
	data->collor = data->collor_depth;
	while (++i < data->iter)
	{
		rand_num = ft_rng() % 100;
		if (rand_num == -1)
			panic("Error calling ft_rng\n!", data);
		fern_algo(&x, &y, rand_num);
		fern_img(x, y, data);
	}
}

void	fern_algo(double *x, double *y, int rand)
{
	if (rand == 0)
	{
		*x = 0;
		*y = 0.16 * (*y);
	}
	else if (rand >= 1 && rand <= 7)
	{
		*x = (-0.15 * *x) + (0.28 * *y);
		*y = (0.26 * *x) + (0.24 * *y) + 0.44;
	}
	else if (rand >= 8 && rand <= 15)
	{
		*x = (0.2 * *x) - (0.26 * *y);
		*y = (-0.23 * *x) + (0.22 * *y) + 1.6;
	}
	else
	{
		*x = (0.85 * *x) + (0.04 * *y);
		*y = (-0.04 * *x) + (0.85 * *y) + 1.6;
	}
}

void	fern_img(double x, double y, t_data *data)
{
	int	index;
	int	x_img;
	int	y_img;

	x_img = ((WIDTH / data->vars.dist_x) * x) + WIDTH / 2 - data->vars.x_min;
	y_img = ((HEIGHT / data->vars.dist_y) * y) + HEIGHT - data->vars.y_min;
	if (x_img >= WIDTH || y_img >= HEIGHT || x_img < 0 || y_img < 0)
		return ;
	index = y_img * data->img.line_len + x_img * (data->img.bpp / 8);
	*((unsigned int *)(data->img.addr + index)) = data->collor;
}
