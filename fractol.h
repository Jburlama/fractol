/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:12:13 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 17:03:05 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <errno.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_var
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	dist_x;
	double	dist_y;
}	t_var;

typedef struct s_data
{
	char		*name;
	void		*disp;
	void		*win;
	t_img		img;
	int			collor;
	int			collor_depth;
	t_complex	c;
	t_var		vars;
	int			iter;
}	t_data;

# define WIDTH 1000.0
# define HEIGHT 1000.0

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define ZOOM_IN 2
# define ZOOM_OUT 1

// render_sets.c
int		render(t_data *data);
int		render_2(t_data *data, int x, int y);

// fractols.c
void	set_julia(t_data *data, char *c_r, char *c_i, char *name);
void	is_valid_julia(char *c_r, char *c_i);
void	set_mandelbrot(t_data *data, char *name);
void	julia(double x, double y, t_data *data);
void	mandelbrot(double x, double y, t_data *data);

// events.c
void	zoom_in_follow(t_data *data, int x, int y);
int		mouse_events(int button, int x, int y, t_data *param);
int		key_release(int keysym, t_data *data);
void	move(int keysym, t_data *data);
int		key_press(int keysym, t_data *data);

//utils
void	mlx_funcs(t_data *data);
void	invalid_args(void);
void	panic(char *str, t_data *data);
int		quit(t_data *data);
void	cleanup(t_data *data);

// zoom.c
void	zoom(t_data *data, int opt);
void	zoom_out_x(t_data *data);
void	zoom_out_y(t_data *data);
void	zoom_in_x(t_data *data);
void	zoom_in_y(t_data *data);

// fern.c
void	set_fern(t_data *data, char *name);
void	fern(double x, double y, t_data *data);
void	fern_img(double x, double y, t_data *data);
void	fern_algo(double *x, double *y, int rand);

#endif
