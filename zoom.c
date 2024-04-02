/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:24:51 by Jburlama          #+#    #+#             */
/*   Updated: 2024/03/28 13:12:46 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *data, int opt)
{
	if (opt == 1)
	{
		zoom_in_x(data);
		zoom_in_y(data);
	}
	else if (opt == 2)
	{
		zoom_out_x(data);
		zoom_out_y(data);
	}
}

void	zoom_out_x(t_data *data)
{
	if (data->vars.x_min >= 0)
	{
		data->vars.x_min += (data->vars.dist_x * (1.0 / 5));
		data->vars.x_max -= (data->vars.dist_x * (1.0 / 5));
		data->vars.dist_x = data->vars.x_max - data->vars.x_min;
	}
	else if (data->vars.x_max <= 0)
	{
		data->vars.x_min += (data->vars.dist_x / 5);
		data->vars.x_max -= (data->vars.dist_x / 5);
		data->vars.dist_x = -data->vars.x_min + data->vars.x_max;
	}
	else
	{
		data->vars.x_min += (data->vars.dist_x * (1.0 / 5));
		data->vars.x_max -= (data->vars.dist_x * (1.0 / 5));
		data->vars.dist_x = -data->vars.x_min + data->vars.x_max;
	}
}

void	zoom_out_y(t_data *data)
{
	if (data->vars.y_min >= 0)
	{
		data->vars.y_min += (data->vars.dist_y * (1.0 / 5));
		data->vars.y_max -= (data->vars.dist_y * (1.0 / 5));
		data->vars.dist_y = data->vars.y_max - data->vars.y_min;
	}
	else if (data->vars.y_max <= 0)
	{
		data->vars.y_min += (data->vars.dist_y * (1.0 / 5));
		data->vars.y_max -= (data->vars.dist_y * (1.0 / 5));
		data->vars.dist_y = -data->vars.y_min + data->vars.y_max;
	}
	else
	{
		data->vars.y_min += (data->vars.dist_y * (1.0 / 5));
		data->vars.y_max -= (data->vars.dist_y * (1.0 / 5));
		data->vars.dist_y = -data->vars.y_min + data->vars.y_max;
	}
}

void	zoom_in_x(t_data *data)
{
	if (data->vars.x_min >= 0)
	{
		data->vars.x_min -= (data->vars.dist_x * (1.0 / 5));
		data->vars.x_max += (data->vars.dist_x * (1.0 / 5));
		data->vars.dist_x = data->vars.x_max - data->vars.x_min;
	}
	else if (data->vars.x_max <= 0)
	{
		data->vars.x_min -= (data->vars.dist_x / 5);
		data->vars.x_max += (data->vars.dist_x / 5);
		data->vars.dist_x = -data->vars.x_min + data->vars.x_max;
	}
	else
	{
		data->vars.x_min -= (data->vars.dist_x * (1.0 / 5));
		data->vars.x_max += (data->vars.dist_x * (1.0 / 5));
		data->vars.dist_x = -data->vars.x_min + data->vars.x_max;
	}
}

void	zoom_in_y(t_data *data)
{
	if (data->vars.y_min >= 0)
	{
		data->vars.y_min -= (data->vars.dist_y * (1.0 / 5));
		data->vars.y_max += (data->vars.dist_y * (1.0 / 5));
		data->vars.dist_y = data->vars.y_max - data->vars.y_min;
	}
	else if (data->vars.y_max <= 0)
	{
		data->vars.y_min -= (data->vars.dist_y * (1.0 / 5));
		data->vars.y_max += (data->vars.dist_y * (1.0 / 5));
		data->vars.dist_y = -data->vars.y_min + data->vars.y_max;
	}
	else
	{
		data->vars.y_min -= (data->vars.dist_y * (1.0 / 5));
		data->vars.y_max += (data->vars.dist_y * (1.0 / 5));
		data->vars.dist_y = -data->vars.y_min + data->vars.y_max;
	}
}
