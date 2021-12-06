/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:46:26 by arohmann          #+#    #+#             */
/*   Updated: 2021/09/29 18:59:28 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	color_sh(t_vars *frac)
{
	double	f;
	int		r;
	int		g;
	int		b;

	f = (double)frac->i / frac->maxiter;
	r = (int)(9 * (1 - f) * (1 - f) * (1 - f) * f * 255);
	g = (int)(15 * (1 - f) * (1 - f) * f * f * 255);
	b = (int)(9 * (1 - f) * f * f * f * 255);
	return (create_trgb(0, b, g, r));
}

int	ft_coloring(t_vars *frac)
{
	int	i;

	i = 0;
	if (frac->color == 0)
		i = (create_trgb(0, 5, frac->i * 5, frac->i * 20));
	else if (frac->color == 1)
		i = color_sh(frac);
	else if (frac->color == 2)
		i = create_trgb(0, 5, frac->i / 4, frac->i * 20);
	else if (frac->color == 3)
		i = create_trgb(0, 100 / i, 5, frac->i * 50);
	else if (frac->color == 4)
		i = create_trgb(0, frac->i * 100, frac->i * 50, frac->i * 50);
	else if (frac->color == 5)
		i = create_trgb(0, 10, frac->i * 300, frac->i * 500);
	return (i);
}
