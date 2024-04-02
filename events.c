/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 06:53:45 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 16:14:52 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	mouse_events(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		zoom(data, ZOOM_IN);
		zoom_in_follow(data, x, y);
	}
	else if (button == 5)
		zoom(data, ZOOM_OUT);
	else
		return (0);
	mlx_destroy_image(data->disp, data->img.img);
	render(data);
	return (0);
}

void	zoom_in_follow(t_data *data, int x, int y)
{
	if (x < WIDTH / 2)
	{
		data->vars.x_min -= (((WIDTH / 2) - x) / (WIDTH / 2))
			* data->vars.dist_x;
		data->vars.x_max -= (((WIDTH / 2) - x) / (WIDTH / 2))
			* data->vars.dist_x;
	}
	else if (x > WIDTH / 2)
	{
		data->vars.x_min += ((x - (WIDTH / 2)) / x) * data->vars.dist_x;
		data->vars.x_max += ((x - (WIDTH / 2)) / x) * data->vars.dist_x;
	}
	if (y < HEIGHT / 2)
	{
		data->vars.y_min -= (((HEIGHT / 2) - y) / (HEIGHT / 2))
			* data->vars.dist_y;
		data->vars.y_max -= (((HEIGHT / 2) - y) / (HEIGHT / 2))
			* data->vars.dist_y;
	}
	else if (y > HEIGHT / 2)
	{
		data->vars.y_min += (((y - (HEIGHT / 2))) / y) * data->vars.dist_y;
		data->vars.y_max += (((y - (HEIGHT / 2))) / y) * data->vars.dist_y;
	}
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	return (0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Right || keysym == XK_Left
		|| keysym == XK_Down || keysym == XK_Up)
		move(keysym, data);
	else if (keysym == XK_plus)
		zoom(data, ZOOM_IN);
	else if (keysym == XK_minus)
		zoom(data, ZOOM_OUT);
	else if (keysym == XK_r)
		data->collor_depth += RED;
	else if (keysym == XK_g)
		data->collor_depth += GREEN;
	else if (keysym == XK_b)
		data->collor_depth += BLUE;
	else if (keysym == XK_i)
		data->iter += 25;
	else
		return (0);
	mlx_destroy_image(data->disp, data->img.img);
	render(data);
	return (0);
}

void	move(int keysym, t_data *data)
{
	if (keysym == XK_Right)
	{
		data->vars.x_min += data->vars.dist_x / 5;
		data->vars.x_max += data->vars.dist_x / 5;
	}
	else if (keysym == XK_Left)
	{
		data->vars.x_min -= data->vars.dist_x / 5;
		data->vars.x_max -= data->vars.dist_x / 5;
	}
	else if (keysym == XK_Up)
	{
		data->vars.y_max -= data->vars.dist_x / 5;
		data->vars.y_min -= data->vars.dist_x / 5;
	}
	else if (keysym == XK_Down)
	{
		data->vars.y_max += data->vars.dist_x / 5;
		data->vars.y_min += data->vars.dist_x / 5;
	}
}
