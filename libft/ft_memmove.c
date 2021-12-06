/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:23:47 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/27 12:02:31 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	if (n == 0)
		return (str1);
	if (ptr1 < ptr2)
	{
		ft_memcpy(str1, str2, n);
	}
	else
	{
		while (n > 0 && ptr1 > ptr2)
		{
			ptr1[n - 1] = ptr2[n - 1];
			n--;
		}
	}
	return (str1);
}
