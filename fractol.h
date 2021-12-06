/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:38:49 by arohmann          #+#    #+#             */
/*   Updated: 2021/10/03 21:26:35 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define WINW 1400
# define WINH 1000

typedef struct s_realn
{
	double	r;
	double	i;
}	t_realn;

typedef struct s_vars
{
	void	*img;
	char	*addr;
	void	*mlx_ptr;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		maxiter;
	int		frac;
	int		color;
	double	arg;
	double	arg2;
	double	sc;
	double	x;
	double	y;
	double	minx;
	double	miny;
	double	maxx;
	double	maxy;
}	t_vars;

int		create_trgb(int t, int r, int g, int b);
int		ft_coloring(t_vars *frac);
void	my_mlx_pixel(t_vars *frac, int x, int y, int color);

int		ft_win_init(t_vars *frac);
int		ft_init_vars(t_vars *frac, char **av, int ac, int call);
int		ft_init_frac(t_vars *frac, char **av, int ac);
void	ft_fractals(t_vars *frac);
int		ft_frac_choose(t_vars *frac);
void	ft_sidebar(t_vars *frac);
int		main(int ac, char **av);

void	ft_hooks(t_vars *frac);
t_realn	ft_offset(t_vars *frac, int x, int y);

int		mandelbrot(t_vars *frac, double c_re, double c_im);
int		inversebrot(t_vars *frac, double c_re, double c_im);
int		julia(t_vars *frac, double z_re, double z_im);
int		snowflake(t_vars *frac, double c_re, double c_im);
#endif