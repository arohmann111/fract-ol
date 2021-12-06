/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidebar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:07:22 by arohmann          #+#    #+#             */
/*   Updated: 2021/09/29 11:20:07 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel(t_vars *frac, int x, int y, int color)
{
	char	*dst;

	dst = frac->addr + (y * frac->line_length + x * (frac->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	ft_sb_text1(t_vars *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1176, 80, 0x00005F3FF,
		"MOVE");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1160, 100, 0x00005F3FF,
		"arrow up");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1110, 120, 0x00005F3FF,
		"arrow left | arrow right");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1160, 140, 0x00005F3FF,
		"arrow down");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1160, 160, 0x00005F3FF,
		"ITERATIONS");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1172, 180, 0x00005F3FF,
		"+ | -");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1176, 200, 0x00005F3FF,
		"MOUSE");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1174, 220, 0x00005F3FF,
		"scroll");
}

static void	ft_sb_text(t_vars *frac)
{
	void	*xpm_file;
	int		bx;
	int		by;

	ft_sb_text1(frac);
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1148, 240, 0x00005F3FF,
		"CHANGE FRACTAL");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1176, 260, 0x00005F3FF,
		"space");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1174, 280, 0x00005F3FF,
		"RESET");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1186, 300, 0x00005F3FF,
		"r");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1172, 320, 0x00005F3FF,
		"ESCAPE");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1182, 340, 0x00005F3FF,
		"esc");
	mlx_string_put(frac->mlx_ptr, frac->mlx_win, 1000, 860, 0x00005F3FF,
		"The Buddhabrot fractal");
	bx = 640;
	by = 640;
	xpm_file = mlx_xpm_file_to_image(frac->mlx_ptr, "bbrot.xpm", &bx, &by);
	mlx_put_image_to_window(frac->mlx_ptr, frac->mlx_win, xpm_file, 995, 450);
}

void	ft_sidebar(t_vars *frac)
{
	int	x;
	int	y;

	x = 1000;
	while (x <= WINW)
	{
		y = -1;
		while (y < WINH)
		{
			my_mlx_pixel(frac, x, y, (create_trgb(0, 5, 20, 80)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->mlx_win, frac->img, 999, 0);
	ft_sb_text(frac);
}
