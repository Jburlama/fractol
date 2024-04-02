/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:31 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 16:57:01 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia(t_data *data, char *c_r, char *c_i, char *name)
{
	is_valid_julia(c_r, c_i);
	data->vars.x_min = -1.5;
	data->vars.x_max = 1.5;
	data->vars.y_min = -1.5;
	data->vars.y_max = 1.5;
	data->c.r = ft_atod(c_r);
	data->c.i = ft_atod(c_i);
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
	data->iter = 150;
	data->collor_depth = BLACK;
}

void	is_valid_julia(char *c_r, char *c_i)
{
	int	i;

	i = 0;
	while (c_r[i] == '-' || c_r[i] == '+')
		i++;
	while (c_r[i])
	{
		if (!ft_isdigit(c_r[i]) && c_r[i] != '.')
			invalid_args();
		i++;
	}
	i = 0;
	while (c_i[i] == '-' || c_i[i] == '+')
		i++;
	while (c_i[i])
	{
		if (!ft_isdigit(c_i[i]) && c_i[i] != '.')
			invalid_args();
		i++;
	}
}

void	julia(double x, double y, t_data *data)
{
	int		i;
	double	z_x;
	double	z_y;
	double	temp_x;
	double	temp_y;

	z_x = x;
	z_y = y;
	i = 0;
	while (i < data->iter)
	{
		temp_x = ((z_x * z_x) - (z_y * z_y)) + data->c.r;
		temp_y = (2 * z_x * z_y) + data->c.i;
		if ((temp_x * temp_x) + (temp_y * temp_y) > 4)
		{
			data->collor = (RED / data->iter) * i + data->collor_depth;
			return ;
		}
		z_x = temp_x;
		z_y = temp_y;
		i++;
	}
	data->collor = BLACK;
	return ;
}

void	set_mandelbrot(t_data *data, char *name)
{
	data->vars.x_min = -2;
	data->vars.x_max = 1;
	data->vars.y_min = -1.5;
	data->vars.y_max = 1.5;
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
	data->iter = 150;
	data->collor_depth = BLACK;
}

void	mandelbrot(double x, double y, t_data *data)
{
	int		i;
	double	z_x;
	double	z_y;
	double	temp_x;
	double	temp_y;

	z_x = 0;
	z_y = 0;
	i = 0;
	while (i < data->iter)
	{
		temp_x = (z_x * z_x - z_y * z_y) + x;
		temp_y = (2 * z_x * z_y) + y;
		if (temp_x * temp_x + temp_y * temp_y > 4)
		{
			data->collor = (RED / data->iter) * i + data->collor_depth;
			return ;
		}
		z_x = temp_x;
		z_y = temp_y;
		i++;
	}
	data->collor = BLACK;
	return ;
}
