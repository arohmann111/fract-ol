/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:14:30 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/28 13:50:33 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intl(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dst;
	int		sign;

	sign = n;
	len = ft_intl(n);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	while (len > 0)
	{
		if (n < 0)
			n = -n;
		dst[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (sign < 0)
		dst[0] = '-';
	if (sign == -2147483648)
		ft_memcpy(dst, "-2147483648", 11);
	return (dst);
}
