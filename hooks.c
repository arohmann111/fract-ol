/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:52:48 by arohmann          #+#    #+#             */
/*   Updated: 2021/10/03 21:24:22 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_move(int key, t_vars *frac)
{
	double	dif;

	dif = frac->maxx - frac->minx;
	if (key == 123)
	{
		frac->minx -= dif * 0.1;
		frac->maxx -= dif * 0.1;
	}
	if (key == 124)
	{
		frac->minx += dif * 0.1;
		frac->maxx += dif * 0.1;
	}
	if (key == 125)
	{
		frac->miny -= dif * 0.1;
		frac->maxy -= dif * 0.1;
	}
	if (key == 126)
	{
		frac->miny += dif * 0.1;
		frac->maxy += dif * 0.1;
	}
	return (0);
}

static int	ft_keys(int key, t_vars *frac)
{
	ft_move(key, frac);
	if (key == 27)
		frac->maxiter -= 10;
	if (key == 24)
		frac->maxiter += 10;
	if (key == 15)
		ft_init_vars(frac, 0, 0, -1);
	if (key == 49)
		frac->frac = (frac->frac + 1) % 4;
	if (key == 8)
		frac->color = (frac->color + 1) % 6;
	if (key == 53)
		exit(0);
	ft_fractals(frac);
	return (0);
}

static int	ft_zoom(int key, int x, int y, t_vars *frac)
{
	double		zoom;
	t_realn		mouse;

	zoom = 1.0;
	mouse = ft_offset(frac, x, y);
	if (key == 5)
		zoom = 0.8;
	if (key == 4)
		zoom = 1.2;
	if ((key == 5 || key == 4) && x >= 0 && x < 1000 && y >= 0 && y < 1000)
	{
		frac->minx = ((frac->minx - mouse.r) * zoom + mouse.r);
		frac->maxx = ((frac->maxx - mouse.r) * zoom + mouse.r);
		frac->miny = ((frac->miny - mouse.i) * zoom + mouse.i);
		frac->maxy = ((frac->maxy - mouse.i) * zoom + mouse.i);
	}
	ft_fractals(frac);
	return (0);
}

t_realn	ft_offset(t_vars *frac, int x, int y)
{
	t_realn	point;

	frac->sc = (frac->maxx - frac->minx) / (WINW - 400 - 1);
	point.r = (frac->minx + frac->sc * x);
	point.i = (frac->maxy - frac->sc * y);
	return (point);
}

void	ft_hooks(t_vars *frac)
{
	mlx_hook(frac->mlx_win, 2, 0, ft_keys, frac);
	mlx_hook(frac->mlx_win, 4, 0, ft_zoom, frac);
	mlx_loop(frac->mlx_ptr);
}
