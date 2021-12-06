/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:15:49 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/25 18:43:16 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	strl;

	strl = ft_strlen(str);
	if (c == '\0')
		return ((char *)(str + strl));
	while (strl >= 0)
	{
		if (str[strl] == c)
			return ((char *)(str + strl));
		strl--;
	}
	return (0);
}
