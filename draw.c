/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:30:54 by arohmann          #+#    #+#             */
/*   Updated: 2021/10/03 21:44:24 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractals(t_vars *frac)
{
	int	x;
	int	y;

	frac->sc = (frac->maxx - frac->minx) / (WINW - 400 - 1);
	x = 0;
	while (x < WINW - 400)
	{
		frac->x = (frac->minx + frac->sc * x);
		y = 0;
		while (y < WINH)
		{
			frac->y = (frac->maxy - frac->sc * y);
			frac->i = ft_frac_choose(frac);
			my_mlx_pixel(frac, x, y, ft_coloring(frac));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->mlx_win, frac->img, 0, 0);
}

int	ft_frac_choose(t_vars *frac)
{
	int	i;

	i = 0;
	if (frac->frac == 0)
		i = mandelbrot(frac, frac->x, frac->y);
	else if (frac->frac == 1)
		i = snowflake(frac, frac->x, frac->y);
	else if (frac->frac == 2)
		i = inversebrot(frac, frac->x, frac->y);
	else if (frac->frac == 3)
		i = julia(frac, frac->x, frac->y);
	return (i);
}
