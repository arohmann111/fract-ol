/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:28:14 by arohmann          #+#    #+#             */
/*   Updated: 2021/09/29 14:28:18 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check(char *s, int *error, int *minus)
{
	int	i;
	int	sign;
	int	dot;

	i = 0;
	sign = 0;
	dot = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr("0123456789+-.", s[i]) == 0)
			break ;
		if (s[i] == '-' || s[i] == '+')
			sign += 1;
		if (s[i] == '.')
			dot += 1;
		i++;
	}
	if (sign == 1 && s[0] == '-')
		*minus = -1;
	if (dot > 1 || sign > 1 || i > 16 || (sign == 1
			&& (s[0] != '-' && s[0] != '+')) || s[i] != '\0')
		*error = -1;
}

double	ft_atod(char *s, int *error)
{
	int		i;
	int		j;
	double	res;
	int		sign;

	sign = 1;
	i = 0;
	j = 0;
	res = 0;
	ft_check(s, error, &sign);
	if (*error == -1)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && s[i] != '.')
		res = res * 10 + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	while (s[i] != '\0')
	{
		res = res * 10 + (s[i++] - '0');
		j++;
	}
	return (sign * res * pow(0.1, j));
}
