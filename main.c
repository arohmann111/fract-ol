/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:08:23 by arohmann          #+#    #+#             */
/*   Updated: 2021/10/03 21:37:28 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_m(void)
{
	write(1, "Error!\nUsage: ./fractol <name>", 23);
	write(1, "\tmandelbrot\tsnowflake\tjulia num1 num2\n", 39);
}

int	main(int ac, char **av)
{
	t_vars	frac;

	if (ac == 2 || ac == 4)
	{
		if ((ft_strcmp("mandelbrot", av[1]) == 0)
			|| (ft_strcmp("julia", av[1]) == 0)
			|| (ft_strcmp("snowflake", av[1]) == 0)
			|| (ft_strcmp("inversebrot", av[1]) == 0))
		{
			ft_win_init(&frac);
			if (ft_init_vars(&frac, av, ac, 0) == -1)
			{
				write(1, "Wrong input\n", 12);
				return (-1);
			}
			ft_sidebar(&frac);
			ft_fractals(&frac);
			ft_hooks(&frac);
		}
		else
			error_m();
	}
	return (0);
}
