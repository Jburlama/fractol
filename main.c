/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:29:41 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/02 15:46:09 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* inicialize data struct and set all to zero
* check for valid input for julia, mandelbort and fern
* if inputs are correct set the values to render the img to the window
* gets to clenup is something fails
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if ((argc == 4 && ft_memcmp(argv[1], "julia\0", 6) == 0)
		|| (argc == 2 && (ft_memcmp(argv[1], "mandelbrot\0", 11) == 0))
		|| (argc == 2 && (ft_memcmp(argv[1], "fern\0", 5) == 0)))
	{
		if (ft_memcmp(argv[1], "julia\0", 6) == 0)
		{
			if (ft_chrcount(argv[2], '.') > 1 || ft_chrcount(argv[3], '.') > 1)
				invalid_args();
			set_julia(&data, argv[2], argv[3], argv[1]);
		}
		else if (ft_memcmp(argv[1], "mandelbrot\0", 11) == 0)
			set_mandelbrot(&data, argv[1]);
		else if (ft_memcmp(argv[1], "fern\0", 5) == 0)
			set_fern(&data, argv[1]);
		mlx_funcs(&data);
		cleanup(&data);
		return (0);
	}
	invalid_args();
}
