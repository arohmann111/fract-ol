/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:30:37 by arohmann          #+#    #+#             */
/*   Updated: 2021/09/29 10:37:22 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_vars *frac, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	i = 0;
	z_re = c_re;
	z_im = c_im;
	while (i < frac->maxiter && (z_re * z_re) + (z_im * z_im) <= 4)
	{
		tmp = z_re;
		z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2 * tmp * z_im + c_im;
		i++;
	}
	return (i);
}

int	snowflake(t_vars *frac, double z_re, double z_im)
{
	int		i;
	double	c_re;
	double	c_im;
	double	tmp;

	i = 0;
	c_re = 0.3;
	c_im = -0.01;
	while (i < frac->maxiter && (z_re * z_re) + (z_im * z_im) <= 5)
	{
		tmp = z_re;
		z_re = (z_re * z_re * z_re * z_re) - (z_im * z_im * z_im * z_im) + c_re;
		z_im = 6 * tmp * z_im + c_im;
		i++;
	}
	return (i);
}

int	julia(t_vars *frac, double z_re, double z_im)
{
	int		i;
	double	c_re;
	double	c_im;
	double	tmp;

	i = 0;
	c_re = frac->arg;
	c_im = frac->arg2;
	while (i < frac->maxiter && (z_re * z_re) + (z_im * z_im) <= 4)
	{
		tmp = z_re;
		z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2 * tmp * z_im + c_im;
		i++;
	}
	return (i);
}

int	inversebrot(t_vars *frac, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	i = 0;
	tmp = c_re;
	c_re = c_re / (c_re * c_re + c_im * c_im);
	c_im = -c_im / (tmp * tmp + c_im * c_im);
	z_re = c_re;
	z_im = c_im;
	while (i < frac->maxiter && (z_re * z_re) + (z_im * z_im) <= 4)
	{
		tmp = z_re;
		z_re = (z_re * z_re) - (z_im * z_im) + c_re;
		z_im = 2 * tmp * z_im + c_im;
		i++;
	}
	return (i);
}
