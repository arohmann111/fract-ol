/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:39:33 by arohmann          #+#    #+#             */
/*   Updated: 2021/10/04 17:12:52 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init_vars(t_vars *frac, char **av, int ac, int call)
{
	frac->arg = 0.3;
	frac->arg2 = -0.01;
	if (call != -1 && ft_init_frac(frac, av, ac) == -1)
		return (-1);
	frac->x = 0;
	frac->y = 0;
	frac->maxiter = 100;
	frac->minx = -2;
	frac->maxx = 2;
	frac->miny = -2;
	frac->maxy = 2;
	frac->color = 0;
	return (0);
}

int	ft_init_frac(t_vars *frac, char **av, int ac)
{
	int	error;

	error = 1;
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		frac->frac = 0;
	else if (ac == 2 && ft_strcmp(av[1], "snowflake") == 0)
		frac->frac = 1;
	else if (ac == 2 && ft_strcmp(av[1], "inversebrot") == 0)
		frac->frac = 2;
	else if ((ac == 2 || ac == 4) && ft_strcmp(av[1], "julia") == 0)
	{
		frac->frac = 3;
		if (ac == 4)
		{
			frac->arg = ft_atod(av[2], &error);
			frac->arg2 = ft_atod(av[3], &error);
			return (error);
		}
	}
	else
		return (-1);
	return (0);
}

int	ft_win_init(t_vars *frac)
{
	frac->mlx_ptr = mlx_init();
	frac->mlx_win = mlx_new_window(frac->mlx_ptr, WINW, WINH, "Fractol");
	frac->img = mlx_new_image(frac->mlx_ptr, WINW - 400, WINH);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bits_per_pixel,
			&frac->line_length, &frac->endian);
	return (0);
}
